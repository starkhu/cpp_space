import torch

x = torch.tensor([2., 1.], requires_grad=True)
y = torch.tensor([[1., 2.],[3., 4.]], requires_grad=True)
z = torch.mm(x.view(1, 2), y)
z.backward(torch.Tensor([[1., 1.]]), retain_graph=True)
print("x.grad is: {}".format(x.grad))
print("y.grad is: {}".format(y.grad))
z.backward(torch.Tensor([[1., 1.]]), retain_graph=True)
print("x.grad is: {}".format(x.grad))
print("y.grad is: {}".format(y.grad))
