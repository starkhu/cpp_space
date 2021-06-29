#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

static std::mutex mu;
static std::timed_mutex tmu;
static std::once_flag oc_s;
static std::once_flag oc_e;
static std::condition_variable cv;

void printStarA() {
  std::call_once(oc_s, [](){ std::cout << "=== welcome to multi-threads tour ===" << std::endl;});
  std::unique_lock<std::mutex> ul(mu);
  for (int i = 0; i < 20; i++) {
    std::cout << "*";
  }
  std::cout << std::endl;
  while(tmu.try_lock_for(std::chrono::milliseconds(200))) {
    std::cout << "this is threadA: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    break;

  }
  cv.wait(ul);
  std::cout << "==== complete multi-threads tour ====" << std::endl;
}

void printStarB() {
  std::call_once(oc_s, [](){ std::cout << "=== welcome to multi-threads tour ===" << std::endl;});
  std::unique_lock<std::mutex> ul(mu);
  for (int i = 0; i < 20; i++) {
    std::cout << "#";
  }
  std::cout << std::endl;
  while(!tmu.try_lock_for(std::chrono::milliseconds(200))) {
    std::cout << "this is threadB: " << std::this_thread::get_id() << std::endl;
    break;
  }
  cv.notify_all();
}

int print_star_demo() {
  std::thread t1(printStarA);
  std::thread t2(printStarB);
  t1.join();
  t2.join();
}
