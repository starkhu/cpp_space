#include<iostream>
#include<thread>

std::thread::id GetThreadId() {
  std::thread::id tid =  std::this_thread::get_id();
  std::cout << "tid is: " << tid << std::endl;
  return tid;
}

unsigned int GetKernels() {
  unsigned int kernels = std::thread::hardware_concurrency();
  std::cout << "kernels is: " << kernels << std::endl;
  return kernels;
}

void ThreadFunction(const int&num) {
  GetThreadId();
  GetKernels();

}

int thread_func() {
  const int flag = 1;  
  std::thread t(ThreadFunction, flag);
  std::cout << "tid is: " << t.get_id() << std::endl;
  if (t.joinable()) {
    t.join();
  }

  return 0;
}

