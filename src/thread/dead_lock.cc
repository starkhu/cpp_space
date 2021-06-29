#include<iostream>
#include<thread>
#include<mutex>

static int flag = 0;
std::mutex mu1;
std::mutex mu2;

void Add10000_1() {
  for (int i=0; i<10000; i++) {
    std::lock(mu1, mu2);
    std::lock_guard<std::mutex> locker1(mu1, std::adopt_lock);
    std::lock_guard<std::mutex> locker2(mu2, std::adopt_lock);
    flag++;
  }
}

void Add10000_2() {
  for (int i=0; i<10000; i++) {
    std::lock(mu1, mu2);
    std::lock_guard<std::mutex> locker2(mu2, std::adopt_lock);
    std::lock_guard<std::mutex> locker1(mu1, std::adopt_lock);
    flag++;
  }
}

int dead_lock_demo() {
  std::thread t1(Add10000_1);
  std::thread t2(Add10000_2);
  t1.join();
  t2.join();
  std::cout << "after t1, t2, flag is " << flag << std::endl;
  return 0;
}
