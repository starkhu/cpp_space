#include<iostream>
#include<string>
#include "fruit.h"

Fruit::Fruit() {
  std::cout << "[constructure]  Fruit::Fruit()" << std::endl;
}

Fruit::Fruit(std::string color) {
  std::cout << "[constructure]  Fruit::Fruit()" << std::endl;
  color_ = color;
}

void Fruit::setColor(std::string color) {
  color_ = color;
}

Fruit::~Fruit() {
  std::cout << "[destructure]  Fruit::~Fruit()" << std::endl;
}
