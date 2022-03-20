torch中对一些功能提供了多个接口，下面记录一下遇到的功能类似的接口

### permute和transpose：
- permute和transpose都是用来对Tensor进行转置的
- 区别在于permute可以进行任意维度的转置。transpose每次只能对tensor的两个维度进行转置。理论上多次进行transpose可以实现permute的功能。
- permute的接口只有tensor.permute()；transpose的接口有torch.transpose()和tensor.transpose两种

### F.linear, torch.matmul 和torch.mm
- 三个接口都可以用来进行矩阵乘的
- torch.mm要求两个输入的维度一致。即torch.mm对输入不支持广播
- torch.matmul不要求输出的维度一致，即torch.mm支持对输入进行广播。例如可以支持input_a的shape为[d,m,n], input_b的shape为[n,k]
- torch.nn.functional.linear(x，w, b)实现的是矩阵乘加bias的操作(xw+b)，计算时需要默认会先对w的最后两个维度进行转置，加偏置操作是可选的。
