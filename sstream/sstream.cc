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

