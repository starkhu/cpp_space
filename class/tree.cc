#include <iostream>
#include <string>
#include "tree.h"

Tree::Tree() {
  std::cout << "Tree::Tree()" << std::endl;
  age_ = 1.0;
  name_ = "tree";
  std::cout << "sizeof name_: " << sizeof(name_) << std::endl;
}
Tree::~Tree() {
  std::cout << "Tree::~Tree()" << std::endl;
}

void Tree::setName(std::string name) {
  name_ = name;
}
void Tree::printName() {
  std::cout << name_ << std::endl;
}
