/************************************************************************************
 *抽象类
 *    如果类中有纯虚函数，则该类称为抽象类。
 *    抽象类不能被实例化
 *static
 *    静态成员属于整个类所有，静态成员函数不含this指针
 *    生命周期不依赖某个对象，属于程序的生命周期
 *    静态成员变量需要在类外单独分配空间，不占用类的空间
 *    静态成员变量存放在全局数据区（.data段）
 *    静态成员变量需要在类外进行初始化，除非是static const型变量，可以在类内进行初始化
 *    公有静态成员函数可以通过类名访问
 *友元函数，友元类：
 *    友元函数可以访问类的所有成员变量，成员函数
 *    友元类的所有函数可以访问类中所有变量函数
 *    友元关系不能被继承（爸爸的朋友不是你的朋友），
 *    单向
 *    友元关系不具备传递性
 ************************************************************************************/

#include <iostream>
#include <string>

class Tree {
 public:
  Tree(std::string name, std::string ctg);
  ~Tree();
  const std::string getName() const;
  void setName(std::string name);
  void printName();
  void printName() const;
  virtual bool isFruitTree() = 0;
  static int getNumOfTree();

  friend void askName(const Tree& tree);

 private:
  float age_;
  std::string name_;
  std::string ctg_;

  static int tree_num_;
};

void askName(const Tree& tree);
