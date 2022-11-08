## 什么是符号冲突
符号冲突是指不同的编译单元含有同名的全局符号，比如同名的全局变量或者同名的全局函数。编译阶段看不出是否有重名的函数，但在运行阶段往往不确定调用重名函数中的哪一个，因此会产生意想不到的错误。

## 案例介绍
a.cc和b.cc 都有receive_data()函数，但二者实现不同。
caller_a.cc 和 caller_b.cc 中分别调用a.cc和b.cc中的receive_data()函数。

### 初步实现：
```
> g++ caller_a.cc a.cc -fPIC -shared -o liba.so
> g++ caller_b.cc b.cc -fPIC -shared -o libb.so
> g++ main.cc -o demo -L. -la -lb
> export LD_LIBRARY_PATH=./
> ./demo
sqrt(100) is 10
sqrt(-900) is -nan
```
从打印信息可见，可执行文件demo调用的是liba.so中的receive_data()_函数，如何让caller_a()函数调用a.cc中的receive_data()函数，caller_b()函数调用b.cc中的receive_data()函数。


## 检验符号冲突的两个手段
### LD_PRELORD
该环境变量的作用是在程序运行之前，优先加载指定的动态链接库。这样在出现同名的符号时，用户可以通过该环境变量来影响程序加载指定链接库的符号。

### example
如果提前加载libb.so会发现，函数调用的是libb.so中的receive_data()函数。
```
export LD_PRELOAD=./libb.so
> ./demo
sqrt(100) is -nan
sqrt(-900) is 30
```

### dlopen

## 避免符号冲突的方案
### Wl,Bsymbolic
Wl表示将紧跟其后的参数，传递给连接器ld。Bsymbolic表示强制采用本地的变量。
```
# -Wl,-Bsymbolic Wl后有一个','，且后续没有空格
> g++ caller_a.cc a.cc -fPIC -shared -o liba.so -Wl,-Bsymbolic
> g++ caller_b.cc b.cc -fPIC -shared -o libb.so -Wl,-Bsymbolic
> g++ main.cc -o demo -L. -la -lb
> export LD_LIBRARY_PATH=./
> ./demo
sqrt(100) is 10
sqrt(-900) is 30
```


### fvisibility
gcc4.0版本提供了可见性控制支持，-fvisibilit编译选项有两个候选值：default和hidden。default表示没有被显示设置为hidden的符号即可对外可见，hidden表示没有显示设置为对外可见的符号均为隐藏。

#### example：
X.cc和caller_X.cc构成一个动态链接库libX.so，以liba.so为例，caller_a()接口供外界调用，对外界可见，但receive_data()不提供给外界调用，该符号不需要对外可见。
因此常见做法是显示声明对外可见的符号，其余符号一律隐藏
```
# caller_a.cc
__attribute__ ((visibility("default"))) void caller_a();
# caller_b.cc
__attribute__ ((visibility("default"))) void caller_b();

> g++ a.cc caller_a.cc -fPIC -shared -o liba.so -fvisibility=hidden
> g++ b.cc caller_b.cc -fPIC -shared -o libb.so -fvisibility=hidden
> g++ main.cc -o demo -L. -la -lb
> export LD_LIBRARY_PATH=./
> ./demo
sqrt(100) is 10
sqrt(-900) is 30
```


### 严格使用命名空间
如果没有动态链接库均设置有命名自己的命名空间，只要命名空间不重名，就可独占符号冲突的问题。因此每个程序员都应该严于律己，养成写命名空间的习惯，造福他人。


## 常见linux命令
### nm 
用于查看库（动态库，静态库，可执行等）中符号
```
>nm -D liba.so |grep receive_data
0000000000000b28 T _Z12receive_dataf
```

### ldd 
用于查看库（动态库，静态库，可执行等）的依赖库
```
 > ldd demo 
        linux-vdso.so.1 =>  (0x00007fffb211b000)
        liba.so => ./liba.so (0x00007fa50f080000)
        libb.so => ./libb.so (0x00007fa50ee7e000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007fa50eafc000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fa50e732000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fa50e429000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fa50f282000)
```
