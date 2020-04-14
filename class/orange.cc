#include<iostream>
#include<string>
#include "orange.h"

Orange::Orange(std::string name,
               std::string ctg,
	       float height) : Tree (name, ctg),
	                       height_(height+1.0),
			       is_fruit_(true) {
  std::cout << "[constructor]  Orange::Orange(): " << getName() << std::endl;
  // is_fruit_ = true;
  fruit_.setColor("yellow");
  // height_ = height;
}

Orange::~Orange() {
  std::cout << "[destructor]  Orange::~Orange(): " << getName() << std::endl;
}

bool Orange::isFruitTree() {
  return is_fruit_;
}

float Orange::getHeight() {
  return height_;
}


