#include <iostream>
#include <string>
#include "tree.h"

Tree::Tree(std::string name, std::string ctg) {
  name_ = name;
  ctg_ = ctg;
  ++tree_num_;
  std::cout << "[constructure]  Tree::Tree(): " << getName() << std::endl;
}

Tree::~Tree() {
  std::cout << "[destructure]  Tree::~Tree(): " << getName() << std::endl;
}

const std::string Tree::getName() const {
  return name_;
}

void Tree::setName(std::string name) {
  name_ = name;
}

void Tree::printName() {
  std::cout << name_ << std::endl;
}

void Tree::printName() const {
  std::cout << name_ << " [const]" << std::endl;
}

int Tree::getNumOfTree() {
  return tree_num_;
}

void askName(const Tree& tree) {
  std::cout << "the tree is: " << tree.getName() << std::endl;
}
