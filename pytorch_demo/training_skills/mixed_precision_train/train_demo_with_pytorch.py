import torch
import torch.nn as nn
import torch.optim as optim
from model import Net
from model import SimpleNet
from fp16 import FP16_Module
from optimizer import FP16_Optimizer


device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
USE_GPU = True if torch.cuda.is_available() else False
ENABLE_HALF = True

def train_demo():
    net = Net()
    if USE_GPU: 
        net.cuda()
    if ENABLE_HALF:
        net = FP16_Module(net)

    optimizer = optim.SGD(net.parameters(), lr=0.01)
    optimizer = FP16_Optimizer(optimizer)
    
    x = torch.randn(1,1,32,32)
    x = x.to(device)
    
    for i in range(30):
        logits = net(x)
        net.zero_grad()
        target = torch.randn(10).to(device).half()
        target = target.view(1, -1)
        criterion = nn.MSELoss()
        
        loss = criterion(logits, target).half()
        backward_step(optimizer, loss)
        print("step is {}, loss is {}".format(i, loss.cpu().item()))
        
        optimizer.step()

def backward_step(optimizer, loss):
    optimizer.backward(loss)
    optimizer.update_master_grads()
    

    


def train_demo_simple():
    net = SimpleNet()
    if USE_GPU:
        net.cuda()
    x = torch.randn(10, 10)
    x = x.to(device)
    logits = net(x)
    optimizer = optim.SGD(net.parameters(), lr=0.01)
    net.zero_grad()
    target = torch.randn(10).to(device)
    target = target.view(1, -1)
    criterion = nn.MSELoss()

    loss = criterion(logits, target)
    loss.backward()
    print("loss is {}".format(loss.cpu().item()))

    optimizer.step()

#train_demo_simple()
train_demo()
