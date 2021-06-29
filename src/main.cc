#include<iostream>
#include "function.h"
#include "template.h"
#include "code_quality.h"
#include "memory_manage.h"
#include "namespace_demo.h"
#include "std.h"

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

void template_demo() {
  template_class_demo();
  template_function_demo();
}

void code_quality() {
  status_demo();
  // valgrind_cases();
}

void memory_manage() {
  memory_manage_demo();
}

void namespace_func() {
  namespace_demo();
}

void std_func() {
  const_demo();
  typeid_demo();
  std_iota();
  max_elements_demo();
}

int main() {
   // func_demo();
   // template_demo();
   // code_quality();
   // memory_manage();
   // namespace_func();
   std_func();
   return 0;
}
