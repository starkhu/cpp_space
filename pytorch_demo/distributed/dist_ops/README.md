# single node multi devices 
python -m torch.distributed.launch --nproc_per_node 2   simple_p2p_demo.py

# multi nodes multi devices 
python -m torch.distributed.launch --nnodes n --node_rank 0 --nproc_per_node m p2p_demo.py
