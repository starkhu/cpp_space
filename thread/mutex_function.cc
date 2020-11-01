#include<iostream>
#include<thread>
#include<mutex>

static int a = 0;
std::mutex mu;

void Add1000() {
  for (int i=0; i<10000; i++) {
    mu.lock();
    a++;
    mu.unlock();
  }
}

int main() {
  std::thread t1(Add1000);
  std::thread t2(Add1000);
  t1.join();
  t2.join();
  std::cout << "after t1 and t2, a is " << a << std::endl;
  return 0;
}
