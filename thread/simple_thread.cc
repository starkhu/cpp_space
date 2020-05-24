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
  std::thread t6([&]{
      std::cout << "this is thread 6" << std::endl;});
  t2.join();
  t3.join();
  t5.join();
  t6.join();
  std::cout << "n is: " << n << std::endl;
}


int main() {
  simpleThread();
}
