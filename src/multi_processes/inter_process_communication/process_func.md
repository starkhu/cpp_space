int pipe(int fd[2]);
创建一个管道，并设置好管道的两个文件描述符，进程通过获取获取文件描述符进而对管道进行读写。
返回值：创建成功返回0，反之返回1。
所在头文件：#include<unistd.h>

int close(int fd);
关闭文件，close会让数据写回磁盘，并释放该文件所占用的资源。
返回值: 成功返回0，反之返回-1
所在头文件：#include<unistd.h>

ssize_t read(int fd, void * buff, size_t count);
把fd所指的文件传送count个字节到buf所指的内存
返回值：返回实际读取的字节数，如果返回0，表示已达文件尾或无可读取的数据。
所在头文件：#include<unistd.h>


ssize_t write(int fd, const void * buff, size_t count);
buf指向的内存写入count个字节到fd所执行的文件。
返回值：返回实际读取的字节数，如果返回0，表示已达文件尾或无可读取的数据。
所在头文件：#include<unistd.h>


pid_t waitpid(pid_t pid, int * status, int options);
当前进程等待指定pid的进程，当指定等待的子进程已经停止或者结束，则立即返回。
所在头文件: #include<sys/wait.h>

pid等待的子进程识别码
|value|function|
|---|---|
|pid<-1|等待进程租号为pid绝对值的任何子进程|
|pid=-1|等待任何子进程|
|pid=0|等待进程组号与当前进程相同的任何子进程|
|pid>0|等待进程号为pid的子进程|
