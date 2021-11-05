
#include<iostream>
#include<functional>

int test_1(int a, std::string b) {
   std::cout << a << " " << b << std::endl;
   return -1;    
}

int main() {
  using namespace std::placeholders;
  auto bind_test1 = std::bind(test_1, 1, "hello");
  auto bind_test2 = std::bind(test_1, _1, _2);
  auto bind_test3 = std::bind(test_1, 3, _1);
  auto bind_test4 = std::bind(test_1, _2, _1);
  bind_test1();
  bind_test2(2, "test2");
  bind_test3("test3", 666);
  bind_test4("test6", 6); 
  return 0;
}
