#include<iostream>
#include<string>
#include "orange.h"

Orange::Orange() {
  std::cout << "Orange::Orange()" << std::endl;
  is_fruit_ = true;
  name_ = "juzi";
  std::cout << "sizeof name_ is: " << sizeof(name_) << std::endl;
}

Orange::~Orange() {
  std::cout << "Orange::~Orange()" << std::endl;
}

void Orange::setName(std::string name) {
  name_ = name;
}
void Orange::printName() {
  std::cout << name_ << std::endl;
}




