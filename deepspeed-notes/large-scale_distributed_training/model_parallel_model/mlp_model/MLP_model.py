import os
import torch
import torch.distributed as dist
from torch.multiprocessing import Process

def mlp_on_one_process(x, w1, w2):
    out1 = torch.matmul(x, w1)
    out2 = torch.matmul(out1, w2)
    print(f"in mlp_on_one_process , out is {out2}")

def mlp_by_model_parallel(x, w1, w2):
    out1 = torch.matmul(x, w1)
    out2 = torch.matmul(out1, w2)
    dist.all_reduce(out2, dist.ReduceOp.SUM)
    print(f"+++ rank is: {dist.get_rank()}, out3: {out2}")


def init_process(rank, size, x, w1, w2):
    #torch.cuda.set_device(rank)
    os.environ['MASTER_ADDR'] = '127.0.0.1'
    os.environ['MASTER_PORT'] = '29501'
    dist.init_process_group(backend, rank=rank, world_size=size)

    partitioned_w_len = int(w1.shape[1]/size)
    narrowed_w1 = w1[:, (rank*partitioned_w_len):(rank+1)*partitioned_w_len]
    narrowed_w2 = w2[(rank*partitioned_w_len):(rank+1)*partitioned_w_len, :]

    mlp_by_model_parallel(x, narrowed_w1, narrowed_w2)


def mlp_demo_by_model_parallel(mp_size, x, w1, w2):
    processes = []
    for rank in range(mp_size):
        p = Process(target=init_process, args=(rank, mp_size, x, w1, w2))
        p.start()
        processes.append(p)

    for p in processes:
        p.join()


if __name__ == "__main__":
    # configure size of the model
    mp_size = 8
    len_a = 2
    len_b = 4
    len_c = 2*mp_size # must be mp_size times
    len_d = 8 # must be mp_size times
    backend = "gloo"

    #init input
    x = torch.randn(len_a, len_b)
    w1 = torch.randn(len_b, len_c)
    w2 = torch.randn(len_c, len_d)

    mlp_on_one_process(x, w1, w2)
    mlp_demo_by_model_parallel(mp_size, x, w1, w2)
