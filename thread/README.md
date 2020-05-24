# 1. thread多线程 

## thread构造函数
 - std::thread()是c++11加进去的特性
### 构造函数
  - 1) thread() 
  - 2) thread(Fn&& fn, Args&& args)  创建一个thread对象，该对象可被joinable()
  - 3) thread(std::thread& t1) = delete; 禁止使用拷贝构造函数
  - 4) thread(std::move(t1)) 移动构造函数，可被使用

## thread成员函数
 - std::thread的常见类成员函数：
 - get_id(): 获取线程id
 - joinable(): 判断线程是否可被join
 - join()
 - detach()
 - swap
 - native_handle
 - hardware_concurrency: 检测硬件并发特性

# 2. mutex互斥量
 - 头文件：#include\<mutex\>

## (1)mutex成员函数
 - lock(): 上锁
 - unlock(): 解锁

## (2)lock_guard
  -实例化：std::lock_guard(std::mutex) lg(mu);
  -在构造函数中加锁，在析构函数中解锁

## (3)unique_lock
### 定义：
 - std::unique_lock为锁管理模板类，是对通用mutex的封装。std::unique_lock对象以独占所有权
 - 的方式(unique owership)管理mutex对象的上锁和解锁操作，即在unique_lock对象的声明周期内，
 - 它所管理的锁对象会一直保持上锁状态；而unique_lock的生命周期结束之后，它所管理的锁对象
 - 会被解锁。unique_lock具有lock_guard的所有功能，而且更为灵活。虽然二者的对象都不能复制，
 - 但是unique_lock可以移动(movable)，因此用unique_lock管理互斥对象，可以作为函数的返回值，
 - 也可以放到STL的容器中。
### 成员函数：
 - 构造函数：禁止拷贝构造函数，允许移动构造函数
 - operator =: 禁止拷贝构造函数，允许移动构造函数
 - lock(): 上锁
 - try_lock(): 尝试给互斥量上锁，如果成功，返回true，否则返回false。无论是否成功，线程立即返回，不会阻塞。
 - try_lock_for(const std::chrono::duration<Rep,Period>& timeout_duration):
 -    如果线程没有获得锁，则该线程阻塞timeout_duration
 - try_lock_util():
 - unlock():
 - release(): 返回unique_lock对象管理的mutex对象的指针，并释放所有权，但不改变mutex对象的状态
 - owns_lock(): 返回当前对象是否获得了锁
 - mutex(): 返回当前std::unique_lock对象管理的mutex对象的指针
 - swap(): 交换两个unique_lock对象

## (4)once_call单次调用
 - std::once_flag of;
 - void once_call(once_flag& flag, Fn&& fn, Args&&...args);

