#include<iostream>
#include "computer.h"

void locate() {
  std::cout << "positiion is: " << __FILE__ << " " << __LINE__ << std::endl;
}

int main() {
  locate();
  int a = 10;
  int b = 20;
  for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
  }
  std::cout << "add(10,20) is: " << add(10, 20) << std::endl;
  return 0;
}
