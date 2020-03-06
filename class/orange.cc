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

int main() {
  Orange org;
  org.setName("two");  
  return 0;
}



