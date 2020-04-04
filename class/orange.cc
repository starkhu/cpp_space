#include<iostream>
#include<string>
#include "orange.h"

Orange::Orange(std::string name, std::string ctg) : Tree (name, ctg){
  std::cout << "Orange::Orange()" << std::endl;
}

Orange::~Orange() {
  std::cout << "Orange::~Orange()" << std::endl;
}

bool Orange::isFruitTree() {
  return is_fruit_;
}



