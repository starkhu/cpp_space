#include<iostream>
#include<thread>
#include<mutex>
#include<deque>
#include<future>

namespace package_task {
std::mutex mu;
std::deque<std::packaged_task<int()> > q;
std::condition_variable cond;

int Square(int n) {
  return n*n;
}

void thread1() {
  std::packaged_task<int()> pt;
  {
    std::unique_lock<std::mutex> locker(mu);
    cond.wait(locker, [](){return !q.empty();});
    pt = std::move(q.front());
  }
  pt();
}

int packaged_task_demo() {
  std::thread t1(thread1);
  std::packaged_task<int()> pt(std::bind(Square, 6));
  std::future<int> ret = pt.get_future();

  {
    std::lock_guard<std::mutex> locker(mu);
    q.push_back(std::move(pt));
  }

  cond.notify_one();

  std::cout << "ret is " << ret.get() << std::endl;

  t1.join();
}
}  // namespace package_task
