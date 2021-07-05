import torch
import torch.nn as nn
import torch.optim as optim
from model import Net


device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
USE_GPU = True if torch.cuda.is_available() else False
USE_FP16 = True
net = Net()

if USE_GPU: 
    net.cuda()
if USE_FP16:
    net.half()

x = torch.randn(1,1,32,32)
x = x.to(device)
if USE_FP16: 
    x = x.half()

for i in range(100):
    out = net(x)
    optimizer = optim.SGD(net.parameters(), lr=0.01)
    net.zero_grad()
    target = torch.randn(10).to(device)
    if USE_FP16: 
        target = target.half()
    target = target.view(1, -1)
    criterion = nn.MSELoss()
    
    loss = criterion(out, target)
    if USE_FP16: 
        loss = loss.half()
    loss.backward()
    print("step is {}, loss is {}".format(i, loss.cpu().item()))
    
    optimizer.step()
