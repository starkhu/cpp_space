# single machine multi cards
python -m torch.distributed.launch --nproc_per_node 2   simple_p2p_demo.py
