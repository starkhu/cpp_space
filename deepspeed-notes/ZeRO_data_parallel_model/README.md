DeepSpeed简介
本文档致力于说明以下几点
- DeepSpeed是什么，解决了什么问题
- 如何将torch的model封装成DeepSpeed的model
- DeepSpeed模型的使用方法
DeepSpeed的内部工作流程是一个很复杂，系统的话题，本文不做讨论，预留以后进行讨论。

## topic1: DeepSpeed是什么， 解决了什么问题
数据并行是分布式训练中最常见也是最重要的一种策略，例如torch中的DDP应用的数据并行策略。但是DDP模式中每张卡都在完整的运行一个网络。如果网络规模较大，单张卡的内存不足以运行一个完整的网络，那么DDP模式也无法应用起来。DeepSpeed框架针对这种问题提出了解决方案，DeepSpeed通过零冗余优化器（ZeRO）和激活重计算等方式能大幅度的减少模型训练时所需的内存。
综上，DeepSpeed是适用于大规模分布式训练的框架，该框架通过对传统的数据并行模式进行优化等策略使单卡大幅减少了训练所需的内存。


## topic2: 如何将torch的model封装成DeepSpeed的model
### 首先介绍一下训练网络的四个阶段
- step1：准备阶段，该阶段用于初始化模型model, 训练数据集dataloader，优化器optimizer，学习率调度器lr_scheduler
    - model, dataloader, optimizer, lr_scheduler = init(...)
- step2: 前向运行阶段，该阶段输入通过模型计算得到logits, logits和labels通过损失函数计算得到loss
    - loss = forward_function(dataloader, model, ...)
- step3: 反向更新梯度阶段
    - loss.backward()
- step4: 优化器更新权值阶段
    - optimizer.step()

### 接下来介绍一下DeepSpeed是如何封装torch模型

- 准备阶段
```
import deepspeed
model_engine, optimizer, trainloader, _ = deepspeed.initialize(
    args=args, model=net, model_parameters=parameters, training_data=train_set)
```

- 前向运行阶段
```
loss = forward_function(...)
```

- 反向更新梯度阶段
```
model_engine.backward(loss)
```

- 优化器更新权值阶段
```
model_engine.step()
```


## topic3: DeepSpeed的使用方式
### 启动方式

#### 单机多卡的启动
单机多卡的启动和ddp模型的启动类似，只需要设置
- 主机上通信的端口号(master_port), 默认值为torch的ddp中设置的默认值29500, 由于其他用户也可能使用这个默认值，因此最好自己单独设置
- 设备数(num_devs)
**代码示例：**
```
run_cmd="deepspeed --master_port ${MASTER_PORT} \
  --num_nodes ${NUM_WORKERS} \
  --num_gpus ${NUM_GPUS_PER_WORKER} \
  launch_network_file.py model_options
```

#### 多机多卡的启动
deepspeed对多机多卡的启动比DDP模型的启动要友好，简单很多。可以在一个机器上启动多机多卡的所有进程。不需要去每个节点上单独设置node_rank等参数。手动点赞。
deepspeed提供了pdsh,openmpi和mvapich三种启动方式，这里仅介绍其中简单易懂的pdsh,具体见链接：...

多机多卡的的启动需要设置的参数更多，主要有：
- 节点数(num_nodes), 机器的数量
- 单机的设备数（num_devs）
- 主机上通信的端口号（master_addr）
- 设备的配置文件（hostfile）
- 启动器（launcher）

**代码示例：**
```
run_cmd="deepspeed --master_port ${MASTER_PORT} \
  --num_nodes ${NUM_WORKERS} \
  --num_gpus ${NUM_GPUS_PER_WORKER} \
  --master_addr  $master_addr\
  --hostfile=$hostfile \
  --launcher="pdsh" \
  launch_network_file.py model_options


# hostfile设置方式(以双机32卡为例)：
node0_ip slots=16
node1_ip slots=16
```

### DeepSpeed中参数的配置
deepspeed提供了很多的优化选型，其中很多优化选项默认是关闭的， 如果模型想要达到最好的优化效果，需要用户自己设置选项。
常见的选项有：
- ZeRO优化器相关选项
- 混合精度选项
- 优化器参数设置选项
- 激活重计算选项


ZeRO优化器相关选项
|option|option_value|instructions|
|---|---|---|
| stage | 0/1/2/3 | ZeRO的优化级别 |
| contiguous_gradients | true/false | 梯度是否使用连续的内存 |
| overlap_comm | true/false | 是否使用多stream并行下发任务 |
| reduce_scatter | true/false | 反向更新梯度阶段对梯度进行通信时，是否使用reduce_scatter/reduce替代allreduce|
| reduce_bucket_size | 正整数 | 单次allreduce的最大通信量 |
| reduce_bucket_size | 正整数 | 单次allgather的最大通信量 |






