/******************************************************************
 *std::bind: 称为网络适配器，用于绑定函数，并且可以赋部分初值。
 *没有赋值的部分使用占位符，栗子：std::placeholders::_1
 *bind中参数顺序可以颠倒
 ******************************************************************/


#include <iostream>
#include <functional>
#include <string>

static void printFunc(int a, std::string str) {
  std::cout << "n is : " << a << ", function name is: "
            << str << std::endl;
} 

int main () {
  using namespace std::placeholders;
  auto bindFunc1 = std::bind(printFunc, 1, "function_1");
  auto bindFunc2 = std::bind(printFunc, _1, _2);
  auto bindFunc3 = std::bind(printFunc, 3, _1);
  auto bindFunc4 = std::bind(printFunc, _2, _1);
  bindFunc1();
  bindFunc2(2, "function_2");
  bindFunc3("function_3", 666, "hhhh");
  bindFunc4("function_4", 4);
}
