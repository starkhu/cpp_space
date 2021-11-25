

## 1、打包demo
### 1.1 package modules to wheel
> python setup.py bdist_wheel  --universal

### 1.2 package modules to egg
> python setup.py bdist_egg

## 2、安装demo
### 2.1 pip install from code
> pip install .


## 3、setup中的参数介绍：

### 3.1 scripts关键字
**3.1.1 需求场景：**

安装一个模块后想要启动该模块时，常见的方式如下：

``` python
python -m torch.distributed.launch ...
```
如果想要用一个命令达到如上的效果，如"torch_dist ..."，则可以通过setup中的scripts达到

**3.1.2 code:**

```python
setuptools.setup(
  ...

  scripts=['bin/forever.sh'],
  cmdclass = {
      "install_scripts":InstallScripts
  }
)
```

**3.1.3 scripts的功能：**

将scripts中的问题拷贝到虚拟环境的bin目录下,如果想要去除文件名中的后缀，可以在cmd_class字典中添加key为"install_scripts"的类进行处理。
