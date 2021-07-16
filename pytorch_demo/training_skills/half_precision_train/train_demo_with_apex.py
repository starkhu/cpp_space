import torch
import torch.nn as nn
import torch.optim as optim
from apex import amp
from model import Net




device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
USE_GPU = True if torch.cuda.is_available() else False
net = Net()

if USE_GPU: 
    net.cuda()

optimizer = optim.SGD(net.parameters(), lr=0.01)

net, optimizer = amp.initialize(net, optimizer, opt_level="O1")

x = torch.randn(1,1,32,32)
x = x.to(device)

for i in range(100):
    out = net(x)

    net.zero_grad()
    target = torch.randn(10).to(device)
    target = target.view(1, -1)
    criterion = nn.MSELoss()
    
    loss = criterion(out, target)
    print("step is {}, loss is {}".format(i, loss.cpu().item()))
    with amp.scale_loss(loss, optimizer) as scaled_loss:
        scaled_loss.backward()
    
    optimizer.step()
