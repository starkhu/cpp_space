#include<iostream>
#include<string>
#include "orange.h"

Orange::Orange() {
  name_ = "xiao";
  age_ = 1.0;
}
void Orange::setName(std::string name) {
  name_ = name;
}
void Orange::printName() {
  std::cout << name_ << std::endl;
}

int main() {
  Orange org;
  org.setName("two");
  org.printName();
  return 0;
}



