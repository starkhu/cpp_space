1.通信操作的过程：
1、创建多个进程，每个进程初始化自己进程组对象。

       1.1 该进程组初始化rank和world_size两个值。即告诉当前进程总共有几个进程需要通信， 当前进程处于第几个进程。

        1.2 设置环境变量“MASTER_ADDR”, "MASTER_PORT"，创建一个套接字用于进程间通信（host端），用于通信域中的cluque_id一样。

2、进程通信

      调用通信原语进行通信

      2.1 rank0进程创建clique_id(大小为128的char型vec)，然后广播到其他进程。这样通信后端（cncl）可以通信ring。这里需要1.2中套接字进行套接字通信。

      2.2 初始化通信子，通信域。并保存到进程组中，供同一进程中其他通信算子使用。（cache机制）

      2.3 调用通信接口。

      等待通信完成。（device上的同步）

3、销毁进程组。

2.创建多进程
path1: 借助torch.distributed.launch包，指定进程参数即可

> python -m torch.distributed.launch --nproc_per_node 2 dist_XXX.py

path2：借助torch.multiprocessing包自己创建多进程

```
import torch.distributed as dist
from torch.multiprocessing import Process

def run_allreduce(rank, size):
    """ Simple point-to-point communication. """
    group = dist.new_group([0, 1])
    tensor = torch.ones(1).to("mlu")
    dist.all_reduce(tensor, op=dist.ReduceOp.SUM, group=group)
    print('Pid is', os.getpid(), 'Rank ', rank, ' has data ', tensor[0])

def init_process(rank, size, fn, backend=backend):
    """ Initialize the distributed environment. """
    os.environ['MASTER_ADDR'] = '127.0.0.1'
    os.environ['MASTER_PORT'] = '29500'
    dist.init_process_group(backend, rank=rank, world_size=size)
    ct.set_device(rank)
    fn(rank, size)


if __name__ == "__main__":
    size = 1
    processes = []
    print("main pid : {}".format(os.getpid()))
    for rank in range(size):
        p = Process(target=init_process, args=(rank, size, run_sample))
        p.start()
        processes.append(p)

    for p in processes:
        p.join()
```

3. 创建销毁进程组
 同一个进程组内的各个进程可以借助通信后端(cncl)可以进行通信。

3.1 创建进程组的方式有两种：
path1:创建一个默认的进程组，

> dist.init_process_group(backend, rank=rank, world_size=world_size)

path2: 如果不想使用默认的进程组，可以自己单独创建进程组

> dist.new_group(rank=None, timeout=datetime.timedelta(0, 1800), backend=None, pg_options=None)

3.2 销毁进程组
new_group之后需要显式销毁进程组。

>dist.destroy_process_group(process_group)

rank_dst: dist.gather(tensor, gather_list=None, dst=0,group=None, async_op=False)

other_rank:dist.gather(tensor, dst=0,group=None, async_op=False)

rank_dst: dist.gather(tensor, scatter_list=None, src=0,group=None, async_op=False)

other_rank:dist.gather(tensor, src=0,group=None, async_op=False)

dist.all_reduce(tensor, group=None, async_op=False)

dist.all_gather(tensor_list, tensor,group=None, async_op=False) 

dist.reduce_scatteroutput,  input_list, op=<ReduceOp.SUM:0>, group=None, async_op=False)

dist.send(tensr, dst, group=None, tag=0）
dist.recv(tensr, src, group=None, tag=0）
dist.isend(tensr, dst, group=None, tag=0）
dist.irecv(tensr, src, group=None, tag=0）


将各个进程中的var，汇聚到主进程的var_list中
将主进程中的var_list分散到各个进程中的var中
将各个进程中的进行tensor规约
将各通信进程汇聚到tensor_list中
通信各进程先对input_list做规约，规约后的结果分散到output中
发送数据到rank_dst进程中（同步操作）
从rank_src进程中接收数据（同步操作）
发送数据到rank_dst进程中（异步操作）
从rank_src进程中接收数据（异步操作）

1、异步操作

torch中的计算算子和通信算子不在同一个queue上，这里的同步是指torch_queue会不会等待通信queue完成操作，是不个设备端的同步操作，如果想要host端也进行同步,需要使能环境变量“CNCL_BLOCKING_WAIT”

2、reduce与all_reduce的区别：

scatter/gather属于parameters server模式，master与slave的代码不同。

all_reduce属于"ring”模式，所有node上代码一致。







