import os
import torch
import torch_mlu
import torch.distributed as dist
import torch.nn.functional as F
from torch.multiprocessing import Process


def self_attention_on_single_process(x, w_q, w_k, w_v, w_o):
    query = F.linear(x, w_q) # query.shape: [bs,s,h]
    key = F.linear(x, w_k)
    value = F.linear(x, w_v)

    attention_scores = torch.matmul(query, key.permute(0,2,1)) # attention_scores.shape: [bs,s,s]
    context_layer = torch.matmul(attention_scores, value) # context_layer.shape: [bs,s,h]
    output = F.linear(context_layer, w_o) # output.shape: [bs,s,h]
    print(f"in simple_self_attention, output is {output}")

def mp_self_attention(x, wq, wk, wv, wo):
    out_q = F.linear(x, wq) #out_q.shape: [bs,s,h/mp]
    out_k = F.linear(x, wk)
    out_v = F.linear(x, wv)
    attention_scores = torch.matmul(out_q, out_k.permute(0,2,1))  # attention_scores: [bs,s,s]
    dist.all_reduce(attention_scores, dist.ReduceOp.SUM)
    context_layer = torch.matmul(attention_scores, out_v)  # attention_scores: [bs,s,h/mp]

    output = F.linear(context_layer, wo) #output.shape: [bs, s, h]
    dist.all_reduce(output, dist.ReduceOp.SUM)
    if dist.get_rank() == 1:
        print(f"+++ rank is: {dist.get_rank()}, out: {output}")


def init_process(rank, size, x, w_q, w_k, w_v, w_o):
    torch.mlu.set_device(rank)
    os.environ['MASTER_ADDR'] = '127.0.0.1'
    os.environ['MASTER_PORT'] = '29501'
    dist.init_process_group(backend, rank=rank, world_size=size)

    partitioned_qkv_len = int(w_q.shape[0]/mp_size)
    x = x.to("mlu")
    narrowed_wq = w_q[rank*partitioned_qkv_len:(rank+1)*partitioned_qkv_len, :].to("mlu") # narrowed_wq.shape: [bs, h, h/mp]
    narrowed_wk = w_k[rank*partitioned_qkv_len:(rank+1)*partitioned_qkv_len, :].to("mlu")
    narrowed_wv = w_v[rank*partitioned_qkv_len:(rank+1)*partitioned_qkv_len, :].to("mlu")
    narrowed_wo = w_o[:, rank*partitioned_qkv_len:(rank+1)*partitioned_qkv_len].to("mlu")

    mp_self_attention(x, narrowed_wq, narrowed_wk, narrowed_wv, narrowed_wo)


def self_attention_demo_by_model_parallel(mp_size, x, w_q, w_k, w_v, w_o):
    processes = []
    for rank in range(mp_size):
        p = Process(target=init_process, args=(rank, mp_size, x, w_q, w_k, w_v, w_o))
        p.start()
        processes.append(p)

    for p in processes:
        p.join()


if __name__ == "__main__":
    # configure model parameters
    mp_size = 8
    bs = 2 # batch_size
    s = 16 # seq_len
    h = 3*mp_size# hidden_size, must be mp_size times
    backend = "cncl"

    # init input_data
    x =   torch.randn(bs, s, h)
    w_q = torch.randn(h, h)
    w_k = torch.randn(h, h)
    w_v = torch.randn(h, h)
    w_o = torch.randn(h, h)
    
    self_attention_on_single_process(x, w_q, w_k, w_v, w_o)
    self_attention_demo_by_model_parallel(mp_size, x, w_q, w_k, w_v, w_o)
