import os
import torch
import torch.distributed as dist
from torch.multiprocessing import Process

os.environ['MASTER_ADDR'] = '127.0.0.1'
os.environ['MASTER_PORT'] = '29500'
backend = 'nccl'
dist.init_process_group(backend)
rank = dist.get_rank()

# simple dist
if rank == 0:
    print("pid is {}, rank is {}".format(os.getpid(), rank))
else:
    print("pid is {}, rank is {}".format(os.getpid(), rank))

torch.cuda.set_device(rank)
tensor = torch.zeros(1).to("cuda:{}".format(rank))
group = dist.new_group([0, 1]) 


if rank == 0:
    tensor += 1
    # dist.send(tensor = tensor, dst=1)
    # dist.isend(tensor = tensor, dst=1)
    #dist.all_reduce(tensor, op=dist.ReduceOp.SUM)
    dist.all_reduce(tensor, op=dist.ReduceOp.SUM, group=group)
else:
    # dist.recv(tensor = tensor, src=0)
    # dist.irecv(tensor = tensor, src=0)
    #dist.all_reduce(tensor, op=dist.ReduceOp.SUM)
    dist.all_reduce(tensor, op=dist.ReduceOp.SUM, group=group)
print('Pid is ', os.getpid(), ', Rank ', rank, ', tensor data is: ', tensor)
