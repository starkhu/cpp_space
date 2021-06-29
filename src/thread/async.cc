#include<iostream>
#include<future>

namespace async1 {

int FutureSquare(int num) {
  std::cout << num*num << std::endl;
  return num*num;
}

void GetParamFromSubThread() {
  std::future<int> f_fuction = std::async(std::launch::async, FutureSquare, 6);
  int f_value = f_fuction.get();
  std::cout << "get value from sub thread: " << f_value << std::endl;
}

}  // namespace async1

namespace async2 {

int FutureSquare(std::future<int>& f_num) {
  int value = f_num.get();
  return value*value;
} 

void SetValueToSubThread() {
  std::promise<int> p;
  std::future<int> f = p.get_future();
  std::future<int> fu = std::async(std::launch::async, FutureSquare, std::ref(f));
  p.set_value(6);
  int result = fu.get();
  std::cout << "result is: " << result << std::endl;
}

int FutureSquareV2(std::shared_future<int> f_num) {
  int value = f_num.get();
  return value*value;
} 

void SetValueToSubThreadV2() {
  std::promise<int> p;
  std::future<int> f = p.get_future();
  std::shared_future<int> sf = f.share();
  std::future<int> fu1 = std::async(std::launch::async, FutureSquareV2, sf);
  std::future<int> fu2 = std::async(std::launch::async, FutureSquareV2, sf);
  std::future<int> fu3 = std::async(std::launch::async, FutureSquareV2, sf);
  p.set_value(6);
  int result = fu1.get();
  std::cout << "result is: " << result << std::endl;
  result = fu2.get();
  std::cout << "result is: " << result << std::endl;
  result = fu3.get();
  std::cout << "result is: " << result << std::endl;
}

}

int async_demo() {
 async1::GetParamFromSubThread();
 async2::SetValueToSubThread();
 async2::SetValueToSubThreadV2();

 return 0;
}
