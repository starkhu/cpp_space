#include<iostream>
#include "function.h"
#include "template.h"
#include "code_quality.h"
#include "memory_manage.h"
#include "namespace_demo.h"
#include "std.h"
#include "class_demo.h"
#include "thread_demo.h"
#include "data_structure.h"
#include "pointer.h"
#include "multi_processes.h"
#include "pre_compile.h"

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
  logger();
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

void class_func() {
  class_demo();
  class_size();
}

void thread_demo() {
  async_demo();
  dead_lock_demo();
  lazy_init_demo();
  print_star_demo();
  sleep_function();
  thread_constructor();
  thread_func();
  cond_var::condition_variable_demo();
  mutex_func::mutex_func();
  package_task::packaged_task_demo();
  uni_lock::add_demo();
}

void data_structure() {
    array_test();
    char_star();
    strcpyTest();
    strncpyTest();
    memcpyTest();
    link_list_demo();
    sstream_demo();
    map_container();
    string_demo();
}

void pointer() {
    nullptr_test();
    second_level_ptr();
    // shared_ptr_test();
    // unique_ptr();
}

void multi_processes() {
    multi_process_demo();
}

void pre_compile() {
    macro_func();
    macro_demo();
}

int main() {
    // func_demo();
    // template_demo();
    code_quality();
    // memory_manage();
    // namespace_func();
    // std_func();
    // class_func();
    // thread_demo();
    // data_structure();
    // pointer();
    // multi_processes();
    // pre_compile();
    return 0;
}
