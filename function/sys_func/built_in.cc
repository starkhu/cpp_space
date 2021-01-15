/************************************************************************************
 *__buildin_expect
 *  函数原型：
 *    函数__builtin_expect()是GCC v2.96版本引入的, 其声明如下:
 *    long __builtin_expect(long exp, long c);
 *  返回值：
 *    返回值等于 第一个参数 exp
 *  功能描述：
 *    这个函数没有功能上的意义，仅提升性能，如果exp 表达式的值有更大概率等于常量 c，则
 *    GCC在编译过程中，会将可能性更大的代码紧跟着前面的代码，从而减少指令跳转带来的性能
 *    上的下降, 达到优化程序的目的.
 ************************************************************************************/
#include <iostream>

void funcBuiltinExpect() {
  int binary = 1;
  if (__builtin_expect(binary, 1)) {
    std::cout << "expect binary is 1" << std::endl;
  } else {
    std::cout << "actually, binary is not 1" << std::endl;
  }
  
  int num_2 = 20;
  int  b = __builtin_expect(num_2, 10);
  std::cout << "b is: " << b << std::endl;
}

int main() {
  funcBuiltinExpect();
  return 0;
}
