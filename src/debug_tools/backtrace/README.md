
### notation:
 - backtrace的实现依赖于栈指针（fp寄存器），在gcc编译过程中任何非零的优化等级（-On参数）或加入了栈指针优化参数-fomit-frame-pointer后多将不能正确得到程序栈信息；
 - backtrace_symbols的实现需要符号名称的支持，在gcc编译过程中需要加入-rdynamic参数；
 - 内联函数没有栈帧，它在编译过程中被展开在调用的位置；
 - 尾调用优化（Tail-call Optimization）将复用当前函数栈，而不再生成新的函数栈，这将导致栈信息不能正确被获取。


### 静态链接情况下定位出错信息
- 编译命令：gcc -g -rdynamic backtrace.c add.c dump.c -o backtrace
- 使用addr2line命令可以将地址翻译成文件名和行号。


### 动态链接情况下定位出错信息
- 编译命令：
    生成libadd.so: gcc -g -rdynamic add.c -fPIC -shared -o libadd.so
    生成backtrace: gcc -g -rdynamic backtrace.c dump.c -L . -ladd -Wl -rpath=. -o backtrace
    
- 使用addr2line命令可以将地址翻译成文件名和行号。

### backtrace函数
- 函数头文件:
```
#include<execinfo.h>
```


```
int backtrace(void **buffer, int size);
```
- 函数功能：该函数用于获取当前线程的调用堆栈， 
- 函数输入：
    - buffer： 获取的堆栈信息将会被存放在buffer中，这是一个指针数组
    -   size： 用来指定buffer中可以保存多少个void*元素。
- 函数返回值：
    - 实际返回的void*元素个数


```
char** backtrace_symbols(void* const *buffer, int size);
```
- 函数功能：将backtrace函数获取的信息转化为一个字符串数组
- 函数输入：
    - buffer: backtrace()获取的堆栈指针
    -   size: backtrace的返回值
- 函数返回值：
    - buffer获取的信息转换成指向字符串数组的指针
- notation：backtrace_symbols生成的字符串占用的内存是malloc出来的，但是是一次性malloc的， 因此释放的时候只需要一次性释放返回的二级指针即可

