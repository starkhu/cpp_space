#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void test_case1() {
  // int* ptr = new int;
  int* ptr = (int*) malloc(sizeof(int));
}

void test_case2() {
  int* ptr = new int[10];
  *(ptr+10) = 10;
}

void test_case3() {
  int x;
  if (x == 10) {
    std::cout << "x";
  }
}

void test_case4() {
  int* ptr = new int[1];
  delete[] ptr;
  delete[] ptr;
}

void test_case5() {
  char str[] = "abcdefg";
  memcpy(str, str+2, 3);
}

void test_case6() {
  int* ptr = new int;
  free(ptr);
}

int valgrind_cases() {
  test_case1();
  test_case2();
  test_case3();
  test_case4();
  test_case5();
  test_case6();
}
