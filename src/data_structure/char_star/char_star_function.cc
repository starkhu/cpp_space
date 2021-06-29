#include <iostream>
#include <string.h>

void strcpyTest() {
  char c1[14] = "summer is hot";
  char *b1 = c1;  
  char c2[25] = "summer is long long long";
  char *b2 = c2;
  std::cout << "c1 is: " << c1 << std::endl;
  std::cout << "c2 is: " << c2<< std::endl;

  std::cout << "strcpy from c2 to c1" << std::endl;
  // strcpy(c1, c2);
  std::cout << "c1 is: " << c1 << std::endl;
  std::cout << "c2 is: " << c2<< std::endl;

  std::cout << "strcpy from c1 to c2" << std::endl;
  strcpy(c2, c1);
  std::cout << "c1 is: " << c1 << std::endl;
  std::cout << "c2 is: " << c2<< std::endl;  //c1 c2打印信息一致，不代表c1 c2相同
  std::cout << "finished======" << std::endl;
}

void strncpyTest() {
  char c1[] = "hello, weekend!";
  char c2[] = "Hello";
  strncpy(c1, c2, 5);
  std::cout << "c1 is: " << c1 << std::endl;
}

void memcpyTest() {
  char c1[] = "hello, weekend!";
  char c2[] = "Hello";
  memcpy(c1, c2, 5);
  std::cout << "c1 is: " << c1 << std::endl;
}
