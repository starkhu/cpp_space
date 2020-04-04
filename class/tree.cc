#include <iostream>
#include <string>
#include "tree.h"

Tree::Tree(std::string name, std::string ctg) {
  std::cout << "Tree::Tree()" << std::endl;
  name_ = name;
  ctg_ = ctg;
}

Tree::~Tree() {
  std::cout << "Tree::~Tree()" << std::endl;
}

std::string Tree::getName() {
  return name_;
}

void Tree::setName(std::string name) {
  name_ = name;
}
void Tree::printName() {
  std::cout << name_ << std::endl;
}
