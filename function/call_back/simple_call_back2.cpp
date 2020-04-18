/************************************************************************************
 *函数指针
 *    指向函数的指针变量
 *    函数指针可以调用函数，也可以作为函数的参数
 *    typedef int (*func_ptr)(float, double); // int 
 *回调函数
 *  定义有两种方式(实质上一样)：
 *    1）为了阅读方便，使用函数指针来做参数
 *    2）直接定义
 ************************************************************************************/

#include <iostream>

template<typename T>
T add(T a, T b) {
  return a + b;
}

template<typename T>
T sub(T a, T b) {
  return a - b;
}

template<typename T>
T mul(T a, T b) {
  return a * b;
}

typedef int (*callback)(int, int);
template <typename T>
void calculate_1(T a, T b, callback cb) {
  std::cout << cb(a, b) << std::endl;
}

template <typename T>
void calculate_2(T a, T b, T (*callback)(T a, T b)) {
  std::cout << callback(a, b) << std::endl;
}

int main() {
  calculate_1(1, 2, add<int>);
  calculate_2(1, 2, sub<int>);
  return 0;
}

