import torch
from torch import nn
from torch import optim
import  torch.nn.functional  as F


# 定义模型
class TheModelClass(nn.Module):
    def __init__(self):
        super(TheModelClass, self).__init__()
        self.conv1 = nn.Conv2d(3, 6, 5)
        self.pool = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.fc1 = nn.Linear(16 * 5 * 5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):
        x = self.pool(F.relu(self.conv1(x)))
        x = self.pool(F.relu(self.conv2(x)))
        x = x.view(-1, 16 * 5 * 5)
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return x

# 初始化模型
model = TheModelClass()


# 初始化优化器
optimizer = optim.SGD(model.parameters(), lr=0.001, momentum=0.9)

# 打印模型的状态字典
print("Model's state_dict:")
for param_tensor in model.state_dict():
    print(param_tensor, "\t", model.state_dict()[param_tensor].size())

# 打印优化器的状态字典
print("Optimizer's state_dict:")
for var_name in optimizer.state_dict():
    print(var_name, "\t", optimizer.state_dict()[var_name])


#save weight, not save global_step, and so on
def save_inference_model(model_name):
    torch.save(model.state_dict(), model_name)

def load_inference_model(model_name):
    model.load_state_dict(torch.load(model_name))
    model.eval()  #set dropout and batch_normalization layer as eval mode, otherwise result of inference maybe different.
    x = torch.randn(1,3,32,32)
    y = model(x)
    print("y is: ", y)

model_name = "./classifier.pt"
load_inference_model(model_name)


train_model = "./clasddifier_train.pt"
def save_model(train_model):
    torch.save(model, train_model)

def load_model(train_model):
    model.load(train_model)
    model.eval()


def save_anything_you_want(model_path):
    epoch=0
    loss=1.0
    torch.save({
                'epoch': epoch,
                'model_state_dict': model.state_dict(),
                'optimizer_state_dict': optimizer.state_dict(),
                'loss': loss,
                }, model_path)

def load_what_you_save(model_path):
    model = TheModelClass()
    #optimizer = TheOptimizerClass()
    
    checkpoint = torch.load(model_path)
    model.load_state_dict(checkpoint['model_state_dict'])
    #optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
    epoch = checkpoint['epoch']
    loss = checkpoint['loss']
    
    model.eval()
    # - or -
    model.train()
