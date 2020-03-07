#include <iostream>
#include <sstream>
#include <string>

void istringstream() {
  std::string str1 = "hello world";
  std::istringstream ss(str1);
  std::string str;
  while(ss >> str) {
  std::cout << str << std::endl;
  }
}

int main() {
  istringstream();
  return 0;
}

