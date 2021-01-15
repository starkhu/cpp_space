/************************************************************************************
 *istringstream: 从string对象中读取
 *ostringstream: 写到string对象中去
 *stringstream: 上述两个类型的集合体，对string对象进行读取
 *str(): 将stringstream对象转换成string对象
 ************************************************************************************/

#include <iostream>
#include <sstream>
#include <string>

void oss_test() {
  std::ostringstream oss;
  oss << "hello " << "code " << "!";
  std::cout << "oss is: " << oss.str() << std::endl;
}

void iss_test() {
  std::string str1 = "hello world";
  std::istringstream iss(str1);
  std::string str;
  while(iss >> str) {
  std::cout << str << std::endl;
  }
}

int main() {
  iss_test();
  oss_test();
  return 0;
}

