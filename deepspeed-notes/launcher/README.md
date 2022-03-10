**一个问题引发的思考与探索**
```
deepspeed框架启动的命令如下：
deepspeed --num_gpus 2 train.py
在我的印象中，以py为后缀的文件都是通过"python XX.py"的方式来调用python解释器执行代码。
那么deepspeed是如何调用python的解释器来执行train.py文件的
```

## 探索历程：

### stage1: 揭开"#!"神秘的面纱

step1: 使用shutil.which定位deepspeed可执行的来源。发现位于虚拟环境的bin文件中
```
>>> import shutil
>>> shutil.which("deepspeed")
'/venv/bin/deepspeed'
```

step2: 果然该目录下有一个deepspeed的可执行文件，接下来就是该如何揭露这个可执行文件的庐山真面目。
尝试用vim文件打开该可执行程序（没有抱很大的希望，因为一般可执行文件不不可读的），然后，，，就打开了，而且是可读的，具体内容如下，

```
#!/venv/bin/python3.6
  
from deepspeed.launcher.runner import main

if __name__ == '__main__':
    main()
```

step3: 看到deepspeed的内容，上面的问题已经有了部分答案。deepspeed悄悄做了一个移花接木，悄无声息的进入了deepspeed/launcher/runner.py文件的主入口。

step4: 但随即另一个问题来了，为什么"deepspeed"能达到"python deepspeed.py"的目标。注意到代码的第一行，如下
```
#!/venv/bin/python3.6
```
调研后发现这行代码的作用是指定代码中的文件用什么解释器执行，至此，问题得到解密


### stage2: DIY一个自己专属的指令

step5: 了解到deepspeed指令工作的原理后，我决定自己尝试DIY一个命令show_time, 用于显示一下当前时间，（虽然linux中已经有实现这个功能的指令）
```
#!/venv/bin/python3.6

import time

print("*" * 30)
print(" " * 1 , time.strftime('%Y-%m-%d  %a  %H:%M:%S'))
print("*" * 30)
```

step6: 给该文件添加执行权限并拷贝到deepspeed相同目录下，执行一下， 有戏，显示效果如下：
```
# show_time
******************************
  2022-03-10  Thu  19:41:53
******************************
```

step7: 如果该文件不拷贝到bin目录下，执行的时候发现找不到这个命令，此时查看环境变量，发现PATH路径下包含了虚拟环境的bin目录，于是添加show_time文件的路径到环境变量PATH中，发现show_time指令就活过来了。
(TBD: 蔡文姬奶英雄的图片，蔡：path, hero： 指令)


## 探索收获：

- 1 脚本中的"#!"用来指定脚本用什么解释器执行
- 2 利用"#!"和PATH环境变量就可在linux上DIY一个自己专属的指令

