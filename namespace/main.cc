/************************************************************************************
 *::是作用域符，是运算符中等级最高的，分为以下三种：
 *global scope(全局作用域符)：用法：::name
 *class scope(类作用域符)：用于static成员，用法：class::name
 *namespace scope(命名空间作用域符)：用法：namespace::name
 ************************************************************************************/


#include <iostream>
#include <string>
int a = 10;

namespace data_space {
std::string space_name = "data_space";
namespace int_space {
  int a = 30;
  void print() {
    std::cout << "space_name: " << space_name << std::endl;
    std::cout << "data::space::space_name: " << data_space::space_name << std::endl;
    std::cout << "a is: " << a << std::endl;
  }
}  // namespace int_space
}  // namespace data_space

namespace data_space {
namespace float_space {
  float a = 30.5;
  void print() {
    std::cout << "space_name: " << space_name << std::endl;
    std::cout << "data::space::space_name: " << data_space::space_name << std::endl;
    std::cout << "a is: " << a << std::endl;
  }
}  // namespace int_space
}  // namespace data_space

namespace print_space {
void globalScope() {
  int a = 20;
  std::cout << "a is: " << a << std::endl;
  std::cout << "::a is: " << ::a << std::endl;
  std::cout << "data_space::int_space::a is: "
            << data_space::int_space::a << std::endl;
}
}

int main() {
  print_space::globalScope();
  data_space::int_space::print();
  data_space::float_space::print();
  return 0;
}
