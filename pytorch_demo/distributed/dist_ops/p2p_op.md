### 点对点通信
点对点通信，顾名思义就同一个group中指定的两个进程之间进行数据通信。
实现的手段就是一个进程执行send操作发送数据，另已一个进程执行recv操作接收数据。


### 算子的python接口
1、同步收发
rank: src
send(tensor, dst, group=group.WORLD, tag=0)

rank: dst
recv(tensor, src，group=group.WORLD, tag=0)

2、异步收发
isend(tensor, dst, group=group.WORLD, tag=0)
irecv(tensor, src，group=group.WORLD, tag=0)

3、将异步收发封装到P2POp类中, 然后调用batch_isend_irecv实现。
P2POp(op, tensor, peer, group=None, tag=0)
batch_isend_irecv(p2p_op_list)
