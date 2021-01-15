/************************************************************************************
 *::是作用域符，是运算符中等级最高的，分为以下三种：
 *global scope(全局作用域符)：用法：::name
 *class scope(类作用域符)：用于static成员，用法：class::name
 *namespace scope(命名空间作用域符)：用法：namespace::name
 ************************************************************************************/


#include<iostream>                                                                                                                                                                                          
namespace ns1 {
  void PrintHello() {
    std::cout << "hello , namespace ns1" << std::endl;
  }
}

namespace ns2 {
  void PrintHello() {
    std::cout << "hello , namespace ns2" << std::endl;
  }
  namespace ns1 {
    void PrintHello() {
      std::cout << "hello , namespace ns2::ns1" << std::endl;
    }
  }
  void test() {
    PrintHello();
    ns1::PrintHello();
    ::ns1::PrintHello();
  }
}


namespace {
  void PrintHello() {
    std::cout << "hello , anonimous namespace" << std::endl;
  }
}

int main() {
  PrintHello();
  ns2::test();
  return 0;
}

