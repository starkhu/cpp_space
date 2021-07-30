### 算子原型
 dist.reduce_scatter(output, input_list, op=<ReduceOp.SUM>, group=None, async_op=False)
- output(tensor): output tensor
- input_list(list[tensor]): list of tensors to reduce and scatter
- group(ProcessGroup, optional): the process group to work on, If None, the default process will be used. async_op
- async_op(bool, optional)

### 函数功能：
各进程input_list做all_reduce操作，然后scatter到各个output中。

### 例子
以如下代码为例，各进程中的input_list是[0,1,2,3]，
all_reduce完之后是[0,4,8,12]
scatter到各个进程中的output分别是[0,4,8,12]

```python
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
output = torch.tensor(0).to("cuda:{}".format(rank))
input_list = [torch.tensor(var).to("cuda:{}".format(rank)) for var in range(4)]


if rank == 0:
    dist.reduce_scatter(output, input_list, op=dist.ReduceOp.SUM, async_op=False)
else:
    dist.reduce_scatter(output, input_list, op=dist.ReduceOp.SUM, async_op=False)
print('Pid is ', os.getpid(), ', Rank ', rank, ', output is: ', output)
```
打印信息
```
Pid is  14230 , Rank  0 , output is:  tensor(0, device='cuda:0')
Pid is  14232 , Rank  2 , output is:  tensor(8, device='cuda:2')
Pid is  14231 , Rank  1 , output is:  tensor(4, device='cuda:1')
Pid is  14233 , Rank  3 , output is:  tensor(12, device='cuda:3')
```
