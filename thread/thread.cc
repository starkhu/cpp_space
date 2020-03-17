#include <iostream>
#include <thread>
#include <mutex>

static std::mutex mu_;
static int cnt_ = 0;
struct Counter {
  void addOne() {
    mu_.lock();
    cnt_++;
    mu_.unlock();}
};

void addN(int& cnt) {
  cnt++;
}

void printHello() {
  std::cout << "Hello" << std::endl;
}

void noParamThread() {
  std::thread trd[10];
  for (int i = 0; i < 10; i++) {
    trd[i] = std::thread(printHello);
  }
  for (auto& t : trd)
     t.join();
}

void oneParamThread() {
  // Counter cnt;
  std::thread tds[10];
  for (int i = 0; i < 10; i++) {
    tds[i] = std::thread(addN, cnt_);
  }
  for (auto t : tds)
    t.join();
  std::cout << "cnt is: " << cnt_ << std::endl; 
}

int main() {
  oneParamThread();
}
