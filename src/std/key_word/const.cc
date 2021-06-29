#include <iostream>
#include <string>

void constVariable() {
  const int a = 1;
  int const b = 2;
  std::cout << "a, b: " << a << ", " << b << std::endl;
}

void constPtr() {
  int var_a = 1;
  const int const_a = 2;
  int var_b = 3;
  const int const_b = 4;

  int* ptr0 = &var_a;
  const int* ptr1 = &var_a;
  //int* ptr2 = &const_a;  // not ok
  const int* ptr3 = &const_a;
  ptr3 = &const_b;

  int* const ptr4 = &var_a;
  // ptr4 = &var_b;  // not ok

  const int* const ptr5 = &var_a;
}

int const_demo() {
  //constVariable();
  constPtr();

  return 0;
}
