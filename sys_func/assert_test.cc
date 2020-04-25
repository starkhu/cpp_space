/************************************************************************************
 *assert(判断表达式)：运行期间的断言
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
