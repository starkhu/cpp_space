#include<iostream>
#include<thread>

class Val {
 public:
    void ThreadLocalValAddOne() {
      static int static_val = 0;
      thread_local int thread_local_val = 0;
      ++thread_local_val;
      std::cout << "thread_local_val_ is: " << thread_local_val << std::endl;
      ++static_val;
      std::cout << "static_val is: " << static_val << std::endl;
    }
};

void PrintFunc() {
  Val v1;
  v1.ThreadLocalValAddOne();
  v1.ThreadLocalValAddOne();
  Val v2;
  v2.ThreadLocalValAddOne();
  v2.ThreadLocalValAddOne();
}

int main() {
  std::thread t1(PrintFunc);
  t1.join();
  std::thread t2(PrintFunc);
  t2.join();

}
