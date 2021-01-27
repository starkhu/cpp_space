#include<iostream>
#include<typeinfo>

#define  size_t long

void test_case() {
  size_t a = 10;
  std::cout << sizeof(size_t) << std::endl;
  std::cout << typeid(a).name() << std::endl;
  std::cout << typeid(long unsigned int).name() << std::endl;
}

int main() {
  test_case();
}
