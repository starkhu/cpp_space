### core_dump问题：

确认是不是内存越界导致的： 多运行两次，如果每次core_dump的点不一致，可能就是内存越界导致的，

这时候就不太好正面定位问题了，因为不清楚是哪里踩坏这块内存的。


### 阅读python源码的一个工具：

traceback：traceback.print_stack()可以打印出对应函数的调用栈
