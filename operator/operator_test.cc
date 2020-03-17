#include <iostream>

void operator_test() {
  int a = 10;
  a = a << 2;
  std::cout << "a << 2, a=" << a << std::endl;
  int b = 0;
  b |= a;
  std::cout << "b |= a, b=" << b << std::endl;
  b = 0;
  b &= a;
  std::cout << "b &= a, b=" << b << std::endl;
}

int main() {
  operator_test();
  return 0; 
}
