#include<iostream>
#include<stdio.h>
#include<typeinfo>

#ifdef __cplusplus
#define FLAG 1
#else
#define FLAG 0
#endif


namespace TestCase1 {

void f1(void* n) {
  std::cout << "void* n" << std::endl;
}
void f2(int n) {
  std::cout << "f2, *n = " << n << std::endl;
}

}

namespace TestCase2 {

void test_case() {
  printf("NULL: %li\n", NULL);
  printf("sizeof(NULL): %lu\n", sizeof(NULL));
  printf("typeid(__null).name(): %s\n", typeid(__null).name());
  printf("typeid(0).name(): %s\n", typeid(0).name());
}

}


int nullptr_test() {
  TestCase1::f1(NULL);
  TestCase1::f2(NULL);
  TestCase2::test_case();
  return 0;
}
