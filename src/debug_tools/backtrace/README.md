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


## 解析打印的调用栈
假设调用栈的打印信息如下：
```
backtrace跟踪到的调用栈打印信息：
stackNum：[00] stackStr：./b(_Z16printf_backtracev+0xa1) [0x55b8230f9a5b]
stackNum：[01] stackStr：./b(_Z4testv+0x9) [0x55b8230f9ae8]
stackNum：[02] stackStr：./b(main+0x9) [0x55b8230f9af4]
stackNum：[03] stackStr：/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xe7) [0x7f480a2c4bf7]
stackNum：[04] stackStr：./b(_start+0x2a) [0x55b8230f98da]
```

### 使用 addr2line 命令可以将地址翻译成文件名和行号。

### 使用 c++filter 命令来解析 backtrace 获取到的文件名
c++filter 无法解析行号信息，所以无法直接解析函数签名，需要先去除签名尾部的行号信息再解析。
```
// 使用 c++filter 的打印信息：
(pytorch) huyongan@MLU370-X4K-ROCE-29:/projs/framework/huyongan/my_space/cpp_space$ c++filt _Z16printf_backtracev
printf_backtrace()
```

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

### Demo：监测程序中出现 Segmentation Fault错误的代码，并打印出错的调用栈
```
> gcc add.c backtrace.c dump.c -rdynamic -o bt
> ./bt 

```





