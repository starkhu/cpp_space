/****************************************************************************
 *std::thread()是c++11加进去的特性
 *std::thread有四个构造函数
 * 1) thread() 
 * 2) thread(Fn&& fn, Args&& args)  创建一个thread对象，该对象可被joinable()
 * 3) thread(std::thread& t1) = delete; 禁止使用拷贝构造函数
 * 4) thread(std::move(t1)) 移动构造函数，可被使用
 ****************************************************************************/



#include <iostream>
#include <thread>


void printHello() {
  std::cout << "Hello" << std::endl;
}

int addOne(int n) {
   return n+1;
}

void addOneRef(int& n) {
  n += 1;
}

std::thread::id getThreadId(const std::thread& t) {
  std::cout << "thread id is : " << t.get_id() << std::endl; 
  return t.get_id();
}

void simpleThread() {
  int n = 0;
  std::thread t1;
  std::thread t2(printHello);
  getThreadId(t2);
  std::thread t3(addOne, n);
  getThreadId(t3);
  std::thread t4(addOneRef, std::ref(n));
  std::thread t5(std::move(t4));
  t2.join();
  t3.join();
  t5.join();
  std::cout << "n is: " << n << std::endl;
}


int main() {
  simpleThread();
}
