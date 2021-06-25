#include<iostream>
#include "function.h"

void func_demo() {
  anonymous();
  bind_demo();

  call_back_demo();
  call_back_demo2();
  call_back_demo_simple();

  assert_demo();
  builtin_demo();
  macro_demo();
  math_demo();
  operator_demo();
  rand_demo();
}

int main() {
   func_demo();
   return 0;
}
