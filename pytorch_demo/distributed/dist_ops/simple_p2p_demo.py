import torch
import torch.distributed as dist

dist.init_process_group("nccl")

rank = dist.get_rank()

counts = 2

if rank == 0:
    torch.cuda.set_device(0)
    tensors = []
    for i in range(counts):
       tensors.append(torch.tensor(range(2), dtype=torch.float32).cuda(0))

    p2p_op_list = []
    for i in range(counts):
        p2p_op_list.append(dist.P2POp(dist.isend, tensors[i], 1))
    reqs = dist.batch_isend_irecv(p2p_op_list)
    for req in reqs:
        req.wait()
    torch.cuda.synchronize()

else:
    torch.cuda.set_device(1)
    tensors = []
    for i in range(counts):
        tensors.append(torch.zeros(2).cuda(1))

    p2p_op_list = []
    for i in range(counts):
        p2p_op_list.append(dist.P2POp(dist.irecv, tensors[i], 0))
    reqs = dist.batch_isend_irecv(p2p_op_list)
    for req in reqs:
        req.wait()
    torch.cuda.synchronize()
    print("*********************tensors0 is: {}".format(tensors))
