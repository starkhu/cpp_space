#include <iostream>
#include "demo.h"


typedef int NUM;
void demo1() {
  NUM number = 1;
  std::cout << "number is " << number << std::endl;
  std::cout << "__WORDSIZE: " << __WORDSIZE << std::endl;

  size_t size = 10;
  std::cout << "len of size_t " << sizeof(size)  << std::endl;

  std::cout << "len of int64_t " << sizeof(int64_t)  << std::endl;
}

Status_t demo2() {
  return SUCCESS;
}
int main() {
  demo1();
  demo2();

  return 0;
}
