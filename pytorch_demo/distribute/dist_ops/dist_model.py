import os
import torch
import torch.distributed as dist
from torch.multiprocessing import Process

def run_sample(rank, size):
    """ Distributed function to be implemented later. """
    print("pid is {}, rank is {}, size is {}".format(os.getpid(), rank, size))

# p2p communicatation sync
def run_send_recv(rank, size):
    tensor = torch.zeros(1).to("cuda:{}".format(rank))
    if rank == 0:
        tensor += 1
        # Send the tensor to process 1
        dist.send(tensor=tensor, dst=1)
    else:
        # Receive tensor from process 0
        dist.recv(tensor=tensor, src=0)
    print('Pid is', os.getpid(), ' Rank ', rank, ' has data ', tensor[0])

# p2p communicatation async
def run_isend_irecv(rank, size):
    tensor = torch.zeros(1).cuda()
    if rank == 0:
        tensor += 1
        dist.isend(tensor=tensor, dst=1)
    else:
        dist.irecv(tensor=tensor, src=0)
    print('isend_irecv, Pid is', os.getpid(), ' Rank ', rank, ' has data ', tensor[0])

# all reduce communication
def run_allreduce(rank, size):
    group = dist.new_group([0, 1]) 
    tensor = torch.ones(1).cuda()
    dist.all_reduce(tensor, op=dist.ReduceOp.SUM, group=group)
    print('all_reduce, Pid is', os.getpid(), 'Rank ', rank, ' has data ', tensor)

def init_process(rank, size, fn, backend):
    #Initialize the distributed environment.
    init_method = "tcp://127.0.0.1:29500"
    torch.cuda.set_device(rank)
    dist.init_process_group(backend, init_method=init_method, rank=rank, world_size=size)
    fn(rank, size)


if __name__ == "__main__":
    size = 2 
    dist_fn = [run_sample]
    backend = 'nccl'
    processes = []
    for rank in range(size):
        # p = Process(target=init_process, args=(rank, size, run_sample, backend))
        # p = Process(target=init_process, args=(rank, size, run_send_recv, backend))
        # p = Process(target=init_process, args=(rank, size, run_isend_irecv, backend))
        p = Process(target=init_process, args=(rank, size, run_allreduce, backend))
        p.start()
        processes.append(p)
    for p in processes:
        p.join()
