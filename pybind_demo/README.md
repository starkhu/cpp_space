# 参考资料：
- https://zhuanlan.zhihu.com/p/192974017


# 1.prepare work

## 下载pybind11仓库
```
git clone https://github.com/pybind/pybind11
```

## 编译&安装pybind11
```
mkdir build & cd build & cmake ..
make check -j 4
make install
```

## 设置PYTHONPATH
export PYTHONPATH=$PYHTONPATH:/path/to/pybind11


# 2.编译c++函数生成python模块
```
g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` pybind_func_demo.cpp -o my_computer`python3-config --extension-suffix`
```
编译结束会生成一个my_computer.cpython-36m-x86_64-linux-gnu.so文件。

## test
```
# set PATHONPATH=$PYHTONPATH:/path/to/my_computer.cpython-36m-x86_64-linux-gnu.so
import my_computer
my_computer.add(10,20)
#打印结果：30
```
# 3.编译c++类生成python模块类
```
g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` pybind_class_demo.cpp -o class_module`python3-config --extension-suffix`
```
## test
编译结束会生成class_module.cpython-36m-x86_64-linux-gnu.so。
```
# set PATHONPATH=$PYHTONPATH:/path/to/class_module.cpython-36m-x86_64-linux-gnu.so
>import class_module
>obj = class_module.PyBindDemo()
>obj.print_msg()
# 打印结果：print
>obj.print_num(10)
# 打印结果：print，10
>obj.print_str("pybind")
# 打印结果：print，pybind
```
