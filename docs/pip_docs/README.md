- 使用pip安装wheel包时，不会覆盖已经安装的包，如果需要强制重装时，需要在安装命令加上" --force-reinstall"
- 如果不想安装依赖时，需要在安装命令加上" --no-deps"

### 1、更换pip源
**阿里源**
vim ~/.pip/pip.conf
```
[global]
index-url = https://mirrors.aliyun.com/pypi/simple/
trusted-host = mirrors.aliyun.com
```
**清华源**
```
[global]
index-url = https://pypi.tuna.tsinghua.edu.cn/simple
```

### 2、commit编辑界面替换成vim编辑界面
>vim ~/.gitconfig
```
[core]
    editor=vim
```

