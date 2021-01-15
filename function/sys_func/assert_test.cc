/************************************************************************************
 *assert(判断表达式)：运行期间的断言
 *  通常Release版本为了追求效率，会优化点assert断言，只有Debug版本为了调试会保留。
 *  在linux系统下，release版本也会保留assert检查，编译加上‘-DNDEBUG’才会跳过assert检查

 *static_assert(判断表达式，提示语句)：编译期间的断言
 ************************************************************************************/

#include <iostream>
void assert_test() {
  int a = 10;
  assert(a == 20);
}

void static_assert_test() {
  static_assert(sizeof(void *) == 8, " os is 64-bit");
}

int main() {
  static_assert_test();
  assert_test();
}
