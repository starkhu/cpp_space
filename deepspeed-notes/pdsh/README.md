## pdsh

### pdsh的安装
```
> apt-get update && apt-get install pdsh
```

### 使用pdsh前的准备：
设置通信的若干节点间进行ssh免密通信

#### 1 安装ssh client/service
```
> apt-get install -y --no-install-recommends openssh-client openssh-server
``

#### 2 将ssh的公钥拷贝到本机和对端机器的指定文件中
```
> ssh-keygen # 生成ssh的私钥和公钥
> 将 ~/.ssh/id_rsa.pub文件中的公钥拷贝到自身/对端服务器的~/.ssh/authorized_keys文件中
```
#### 3 开启ssh服务
```
> service ssh start

检查ssh服务是否开启成功, 使用如下命令
> service ssh status

如果开启成功，会显示：
>  * sshd is running
```

#### 4 检查是否完成免密通信
```
# 确认是否可以免密登录本机
> ssh localhost
# 确认是否可以免密登录其他机器
> ssh user_name@ip_addr
如果以上命令可以成功登录本机/其他机器的终端，则免密登录设置成功
```


### pdsh的使用方式
```
pdsh -w ssh:hostname1, ssh:hostname2 "shell_cmd" ， 其中hostname1也可替换成ip. 
```

example
```
(torch) root@f46b04fa59ea:/tools/# pdsh -w ssh:10.0.1.13,ssh:10.0.1.15 "cd /tools/;python print_hello.py;date"
10.0.1.15: ('hello, pid is ', 41208)
10.0.1.15: Fri Mar  4 17:09:48 CST 2022
10.0.1.13: ('hello, pid is ', 33936)
10.0.1.13: Fri Mar  4 17:09:48 CST 2022
```
