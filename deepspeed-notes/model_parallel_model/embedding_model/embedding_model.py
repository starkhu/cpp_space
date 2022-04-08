import os
import torch
import torch.nn.functional as F
import torch.distributed as dist
from torch.multiprocessing import Process

def embedding_on_single_process(input_index, weight):
    embedded_output = F.embedding(input_index, weight)
    print(f"on single process, embedded_output is: {embedded_output}")

def embedding_by_model_parallel(backend, rank, vocab_size, mp_size, input_index, embedding_weight):
    os.environ['MASTER_ADDR'] = '127.0.0.1'
    os.environ['MASTER_PORT'] = '29501'
    dist.init_process_group(backend, rank=rank, world_size=mp_size)

    vocab_start_index = int(rank * (vocab_size/mp_size))
    vocab_end_index = int((rank+1) * (vocab_size/mp_size))
    input_mask = (input_index < vocab_start_index) | (input_index >= vocab_end_index)
    masked_input = input_index - vocab_start_index
    masked_input[input_mask] = 0
    output = F.embedding(masked_input, embedding_weight)
    output[input_mask, :] = 0.0
    dist.all_reduce(output)
    print(f"by model parallel, rank is {rank}, embedded_output is: {output}")

def launch_embedding_by_model_parallel(backend, vocab_size, mp_size, input_index, embedding_weight):
    processes = []
    for rank in range(mp_size):
        vocab_start_index = int(rank * (vocab_size/mp_size))
        vocab_end_index = int((rank+1) * (vocab_size/mp_size))
        partitioned_vocab_size_len = int(vocab_size/mp_size)
        narrowed_embedding_weight = embedding_weight[vocab_start_index:vocab_end_index, :]
        p = Process(target=embedding_by_model_parallel,
                    args=(backend, rank, vocab_size, mp_size, input_index, narrowed_embedding_weight))
        p.start()
        processes.append(p)

    for p in processes:
        p.join()

if __name__ == "__main__":
    vocab_size = 20
    hidden_size = 8
    input_index = torch.Tensor([12,7,3,15,16,1]).to(torch.int64)
    embedding_weight = torch.randn([vocab_size, hidden_size])


    embedding_on_single_process(input_index, embedding_weight)


    mp_size = 4
    backend = 'gloo'
    launch_embedding_by_model_parallel(backend, vocab_size, mp_size, input_index, embedding_weight)
