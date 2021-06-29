#include<iostream>
#include<thread>
#include<mutex>
std::once_flag m_flag;

void OnceCall() {
  std::cout << "this function will be called once" << std::endl;
}

void LazyInitializer() {
  std::call_once(m_flag, OnceCall);
}

int lazy_init_demo() {
  std::thread t1(LazyInitializer);
  std::thread t2(LazyInitializer);
  t1.join();
  t2.join();
  return 0;

}
