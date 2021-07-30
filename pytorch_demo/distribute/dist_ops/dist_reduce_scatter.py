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
var = torch.tensor(rank+10).to("cuda:{}".format(rank))
var_list = [torch.tensor(var).to("cuda:{}".format(rank)) for var in range(4)]


if rank == 0:
    dist.reduce_scatter(var, var_list, op=dist.ReduceOp.SUM, async_op=False)
else:
    dist.reduce_scatter(var, var_list, op=dist.ReduceOp.SUM, async_op=False)
print('Pid is ', os.getpid(), ', Rank ', rank, ', tensor data is: ', var)

