/******************************************************************
 *std::thread的常见类成员函数：
 *get_id(): 获取线程id
 *joinable(): 判断线程是否可被join
 *join()
 *detach()
 *swap
 *native_handle
 *hardware_concurrency: 检测硬件并发特性
 ******************************************************************/


#include<thread>


std::thread::id getThreadId() {
  std::thread::is tid =  std::this_thread::get_id();
  return tid;
}
