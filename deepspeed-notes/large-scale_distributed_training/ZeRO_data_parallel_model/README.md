DeepSpeed简介

本文档致力于说明以下几点
- DeepSpeed是什么，解决了什么问题
- 使用 DeepSpeed 封装 PyTorch 模型
- DeepSpeed的启动方式
- DeepSpeed中参数的配置

DeepSpeed的内部工作流程就说来话长，这里按住不表，预留以后进行讨论。

## DeepSpeed是什么， 解决了什么问题
随着深度学习的发展，业界发现模型越大，训练出来的效果越好，模型越来越大变成了深度学习领域一个显著的趋势。
当模型越来越大，即模型中的神经元越来越多，权值数量也越来越多，运行模型所需要的内存超过单张卡的内存时，
此时需要多台机器很多张卡协调工作才能运行起整个模型。而如何简单高效地训练大规模的模型成为业界积极探索的一个挑战性课题。
DeepSpeed 设计实现了以下特性来内存供需不平衡的问题：

- 实现 ZeRO 零冗余优化器，在数据并行模式下可消除多卡间冗余的梯度，权值和状态值。
- 实现流水并行策略，将模型切分若干份子模型，将每一份子模型载入不同的设备。
- 实现激活重计算功能，前向计算过程中仅保存少量标记算子的激活值，可大幅减少激活值消耗的内存。
- 实现负载均衡技术，将前向计算中的暂时用不到的激活值临时换出到 CPU 主存上，等需要时再换入到 Device 上。

综上，DeepSpeed是适用于大规模分布式训练的框架，该框架通过对传统的数据并行模式进行优化等策略使单卡大幅减少了训练所需的内存。


## 使用 DeepSpeed 封装 PyTorch 模型
### 训练网络的四个阶段
**准备阶段**
该阶段用于初始化模型model, 训练数据集dataloader，优化器optimizer，学习率调度器lr_scheduler
```
    model, dataloader, optimizer, lr_scheduler = init_model(...)
```

**前向运行阶段**
该阶段输入通过模型计算得到logits, logits和labels通过损失函数计算得到loss
```
    loss = forward_function(dataloader, model, ...)
```

**反向更新梯度阶段**
```
    loss.backward()
```

**优化器更新权值阶段**
```
    optimizer.step()
```

### 使用 DeepSpeed 封装 PyTorch 模型

**准备阶段**
```
import deepspeed
model_engine, optimizer, trainloader, _ = deepspeed.initialize(
    args=args, model=net, model_parameters=parameters, training_data=train_set)
```

**前向运行阶段**
```
loss = forward_function(...)
```

**反向更新梯度阶段**
```
model_engine.backward(loss)
```

**优化器更新权值阶段**
```
model_engine.step()
```


## DeepSpeed 的启动方式
#### 单机多卡的启动
单机多卡的启动需要如下设置:

|选项|选项的含义|默认值|
|---|---|---|
| num_devs | 单机上使用的设备数 | 1 |
| master_port | 与主机通信的端口号 | 29500 |

*注：其中master_port的默认值同torch的ddp中设置的默认值29500，其他用户经常也会使用这个值，为了避免冲突，建议用户设置成其他值*

以下是单机多卡的启动示例：

```
run_cmd="deepspeed --master_port ${MASTER_PORT} \
  --num_gpus ${NUM_GPUS_PER_WORKER} \
  launch_network_file.py model_options
```

#### 多机多卡的启动
DeepSpeed 对多机多卡的启动比DDP模型的启动要友好，简单很多。可以在一个机器上启动多机多卡的所有进程。不需要去每个节点一一设置。手动点赞。
DeepSpeed 提供了 PDSH, OpenMPI 和 MVAPICH 三种启动方式，这里仅介绍其中简单易懂的pdsh,具体见链接：...

多机多卡的的启动需要设置如下参数

|选项|选项的含义|默认值|
|---|---|---|
| num_nodes | 机器的数量数 | 1 |
| num_devs | 单机上使用的设备数 | 1 |
| master_addr | 主机上地址 | localhost |
| master_port | 与主机通信的端口号 | 29500 |
| hostfile | 设备的配置文件 | none |
| launcher | 启动器类型 | pdsh|

其中hostfile文件需要按照一定的格式设置，以双机32卡的网络规模为例，设置方式如下：
```
node0_ip slots=16
node1_ip slots=16
```

启动代码示例
```
run_cmd="deepspeed --master_port ${MASTER_PORT} \
  --num_nodes ${NUM_WORKERS} \
  --num_gpus ${NUM_GPUS_PER_WORKER} \
  --master_addr  $master_addr\
  --hostfile=$hostfile \
  --launcher="pdsh" \
  launch_network_file.py model_options
```

### DeepSpeed中参数的配置

deepspeed提供了很多的优化选型，其中很多优化选项默认是关闭的， 如果想要达到最好的优化效果，需要用户自己设置选项。

| 选项 | 默认值 | 含义 |
|---|---|---|
| train_micro_batch_size_per_gpu | 1 | 单卡的batch_size |
| gradient_accumulation_steps | 1 | 每隔若干代更新梯度 |
| steps_per_print | 50 | 每隔若干代打印一次当前的状态 |

ZeRO优化器相关选项

| 选项 | 默认值 | 含义 |
|---|---|---|
| stage | 0 | ZeRO的优化级别 |
| contiguous_gradients | false | 梯度是否使用连续的内存 |
| overlap_comm | false | 是否使用多stream并行下发任务 |
| reduce_scatter | false | 反向更新梯度阶段是否使用优化 |
| reduce_bucket_size | 5e8 | 单次allreduce的最大通信量 |
| reduce_bucket_size | 5e8 | 单次allgather的最大通信量 |

混合精度相关选项

| 选项 | 默认值 | 含义 |
|---|---|---|
| loss_scale | 2^32 | loss_scale的初始值 |
| loss_scale_window | 1000 | loss_scale值变化的窗口阈值 |
| min_loss_scale | 0 | loss_scale下溢的最小值 |

 优化器相关选项

| 选项 | 默认值 | 含义 |
|---|---|---|
| type | adam | 优化器类型 |
| lr | 0.0001 | 学习率 |
| betas | 0.9/0.95 | 计算梯度及梯度平方的平均值的系数 |
| eps | 1e-8 | 保证分母大于0而加到分母里的项 |
| weight_decay | 1e-1 | 权重衰减系数 |
