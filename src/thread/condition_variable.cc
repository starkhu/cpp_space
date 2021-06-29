#include<deque>
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

namespace cond_var {
std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

void Producer() {
  for(int i=0; i<=6; i++){
    std::unique_lock<std::mutex> locker(mu);
    std::cout << "call producer " << i << std::endl;
    q.push_front(i);
    locker.unlock();
    cond.notify_one();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void Consumer() {
  int data = 0;
  while(data < 6) {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker, [](){return !q.empty();});
    std::cout << "call consumer " << data << std::endl;
    data = q.back();
    std::cout << "get data from queue, " << data << std::endl;
    std::cout << std::endl;
    q.pop_back();
    locker.unlock();
  }
}

int condition_variable_demo() {
  std::thread t1(Producer);
  std::thread t2(Consumer);
  t1.join();
  t2.join();
  return 0;
}

}  // namespace cond_var
