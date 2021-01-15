/********************************************************************************************
 *sizeof与strlen的区别：
 *   1 sizeof 是运算符，strlen是函数
 *   2 sizeof显示变量所占内存空间，strlen只接受char*变量的参数
 * 指针size:
 *  1 sizeof(指针)的值一般是4或8，64位是为系统为8，因为64根地址线可以寻址的空间达2^64Bytes。
 *  故每个地址也需要64位表示。
 *notation
 *  1 char* arr = "test"的写法是有问题的，原因是“test”是常量，不能用普通指针只想常量，防篡改。
 *    正确写法：const char* arr = "test";
 *          or  char arr[] = "test";  //赋值总是没毛病的
 ********************************************************************************************/

#include <iostream>

void purePrint() {
  std::cout << "size of int is: " << sizeof(int) << std::endl;
  std::cout << "size of long is: " << sizeof(long) << std::endl;
  std::cout << "size of long int is: " << sizeof(long int) << std::endl;
  std::cout << "size of long long is: " << sizeof(long long) << std::endl;
  std::cout << "size of double is: " << sizeof(double) << std::endl;
  std::cout << "size of long double is: " << sizeof(long double) << std::endl;
}

void sizePrint(int arr[]) {
  std::cout << "in sizePrint function, sizeof arr is " << sizeof(arr) << std::endl;
}

void stringPrint() {
  const char* c_arr = "abcd";
  char c_arr1[] = "abcd";
  std::cout << "size of c_arr is " << sizeof(c_arr) << std::endl;
  std::cout << "strlen of c_arr is " << strlen(c_arr) << std::endl;
  std::cout << "size of c_arr1 is " << sizeof(c_arr1) << std::endl;
  std::cout << "strlen of c_arr1 is " << strlen(c_arr1) << std::endl;
}

int main() {
#if 1
  int arr[10] = {1, 2, 3};
  std::cout << sizeof(arr) << std::endl;
  sizePrint(arr);
#endif

  //part two
#if 1
  stringPrint();
#endif

purePrint();
  return 0;
}
