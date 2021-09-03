import torch                                                                                                                                                                                                
import torch.distributed as dist
import argparse
from torch.nn.parallel import DistributedDataParallel as DDP

backend = "cncl"
dist.init_process_group(backend=backend)
local_rank = dist.get_rank()
torch.cuda.set_device(local_rank)

# in_feature, out_feature
model = torch.nn.Linear(10, 1).to("gpu")
model = DDP(model, device_ids=[local_rank], output_device=local_rank)

outputs = model(torch.randn(10, 10).to("gpu"))
labels = torch.randn(10, 1).to("gpu")
loss_fn = torch.nn.MSELoss()
loss = loss_fn(outputs, labels)
loss.backward()
optimizer = torch.optim.SGD(model.parameters(), lr=0.001)
optimizer.step()
print("loss is {}".format(loss.item()))

