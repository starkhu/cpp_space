#include <iostream>
#include <string>

class Tree {
 public:
  Tree();
  ~Tree();
  virtual void setName(std::string name);
  virtual void printName();
 private:
  float age_;
  std::string name_;
};
