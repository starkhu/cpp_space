/************************************************************************************
 *抽象类
 *    如果类中有纯虚函数，则该类称为抽象类。
 *    抽象类不能被实例化
 ************************************************************************************/

#include <iostream>
#include <string>

class Tree {
 public:
  Tree(std::string name, std::string ctg);
  ~Tree();
  std::string getName();
  void setName(std::string name);
  void printName();
  virtual bool isFruitTree() = 0;
 private:
  float age_;
  std::string name_;
  std::string ctg_;
};
