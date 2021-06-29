#include<iostream>
#include<thread>
#include<mutex>
#include<future>
#include<condition_variable>
#include<chrono>

std::mutex mu;
std::condition_variable cond;

void PrintHello() {
  std::cout << "print hello" << std::endl;
}

void sleep_function() {
  std::thread t(PrintHello);
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now() + std::chrono::milliseconds(500);
  std::this_thread::sleep_until(tp);
  t.join();

  // locker
  std::mutex mu1;
  std::unique_lock<std::mutex> locker(mu1);
  // locker.try_lock_for(std::chrono::milliseconds(500));
  // locker.try_lock_until(tp);

  // condition_variable
  std::condition_variable c;
  c.wait_for(locker, std::chrono::milliseconds(500));
  c.wait_until(locker, tp);

  // future
  std::promise<int> p;
  std::future<int> f = p.get_future();
  f.wait_for(std::chrono::milliseconds(500));
  f.wait_until(tp);

}

