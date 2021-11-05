## 1 GNU C库
GNU C库，又名glibc，是GNU计划所实现的C标准库。尽管其名字中带有“C库”，但它现在也直接支持C++（以及间接支持其他编程语言）。它是自由软件基金会（FSF）在20世纪90年代初为他们的GNU操作系统设计的。它为GNU系统，GNU/Linux系统和一些其他的类Unix系统提供了系统核心库。这些库提供了关键的API，包括ISO C11、POSIX.1-2008和BSD所规定的API和一些底层API，包括open、read、write、malloc、printf、getaddrinfo、dlopen、pthread_create、crypt、login、exit等

## 2 GCC
GCC是GNU编译器集合，最开始它是编译C编译器，是GNU C Compiler的缩写，后来随着这个项目集成了更多不同语言的编译器，GCC就变成了一堆编译器的集合，缩写含义改为GNU Compiler Collection。
GCC中我们最常用的两个命令就是gcc和g++, 分别用来编译C语言和C++语言。
C语言的编译器是cc1，C++语言的编译器是cc1plus,编译完之后将源码编译成汇编代码。
然后driver调用as将汇编代码改成二进制代码。
最后调用ld，将二进制代码链接在一起。


## 3 \_\_attribute\_\_
\_\_attribute\_\_是GNU C的一大特性，用于告诉gcc编译器对代码做一些特定的操作。
每个关键字对应一个操作，具体介绍如下

### 3.1) aligned
指定对象的对齐格式（以字节为单位）
 - 对齐的长度需是2的指数倍
 - \_\_attribute\_\_((aligned))采用的是默认对齐数，和链接器有关
 - attribute 属性的效力与连接器有关，如果连接器最大只支持16 字节对齐，那么定义32 字节对齐也没用


### 3.2) packed
针对struct和union类型， 对其类型中的每一个变量进行内存约束， 告诉编译器取消编译过程中的优化对齐。

### 3.3) constructor
会在目标文件的.ctors中执行，常用来做一些隐形的初始化工作。
 - g++不支持constructor, gcc支持, 比较特殊
 - 如果有多个constructor函数，通过设置数值来确定调用的优先级，数值越小，优先级越高。0-100是系统调用的，一般不建议使用。

### 3.4) destructor 
会在目标文件的.dtors中执行
 - g++和gcc都支持destructor
 - 如果有多个destructor函数，通过设置数值来确定调用的优先级，数值越小，优先级越低。0-100是系统调用的，一般不建议使用。


### 3.5) at
绝对定位，可以把变量或函数绝对定位到Flash中，或者定位到RAM。
 - 定位到flash中，一般用于固化的信息，如出厂设置的参数，上位机配置的参数，ID卡的ID号，flash标记等等
 - 定位到RAM中，一般用于数据量比较大的缓存，如串口的接收缓存，再就是某个位置的特定变量


