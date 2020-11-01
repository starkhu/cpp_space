#include<iostream>
#include<thread>
#include<mutex>

static int a = 0;
std::mutex mu;

void Add1000() {
  for (int i=0; i<10; i++) {
    std::unique_lock<std::mutex> locker(mu, std::defer_lock);
    std::cout << "start unique lock" << std::endl;
    locker.lock();
    a++;
    locker.unlock();
    std::cout << "complete unique lock" << std::endl;
    
    locker.lock();
    std::unique_lock<std::mutex> locker2 = std::move(locker);
    a++;
    locker2.unlock();

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
