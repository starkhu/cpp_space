import time
import torch
import torch.distributed as dist

dist.init_process_group("nccl")

num_iterations = 1

# small tensor ok
tensor_sizes = [10] * 1

# large tensor do not work
#tensor_sizes = [100000] * 7

rank = dist.get_rank()

groups = []
for i in range(len(tensor_sizes)):
    groups.append(dist.new_group([0, 1]))

if rank == 0:
    torch.cuda.set_device(0)
    
    for j in range(num_iterations):
        tensors = []
        for tensor_size in tensor_sizes:
            tensors.append(torch.tensor(range(tensor_size), dtype=torch.float32).cuda(0))

        start = time.time()
        p2p_op_list = []
        for i, tensor in enumerate(tensors):
            p2p_op_list.append(dist.P2POp(dist.isend, tensor, 1, groups[i]))
        reqs =  dist.batch_isend_irecv(p2p_op_list)
        for req in reqs:
            req.wait()
        torch.cuda.synchronize()
        print(f"{j} - Send[batch] - Total: {time.time() - start}")

else: # rank = 1
    torch.cuda.set_device(rank)

    for j in range(num_iterations):
        tensors = []
        for tensor_size in tensor_sizes:
            tensors.append(torch.zeros(tensor_size).cuda(1))

        start = time.time()
        p2p_op_list = []
        for i, tensor in enumerate(tensors):
            p2p_op_list.append(dist.P2POp(dist.irecv, tensor, 0, groups[i]))

        reqs =  dist.batch_isend_irecv(p2p_op_list)
        for req in reqs:
            req.wait()
        torch.cuda.synchronize()
        print(f"{j} - Recv[batch] - Total: {time.time() - start}")
        print(tensors)
