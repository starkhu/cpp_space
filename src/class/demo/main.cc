/**********************************************************************************
 *虚函数表：
 *    如果类的成员函数有虚函数，则类的大小需要加一个虚函数指针，该指针指向虚函数表
 *    类的虚函数表在编译器就生成
 *    同一个的类的不同实例化对象共享同一个虚函数表
 *    父类和子类的虚函数表不是同一个
 **********************************************************************************/
// #include "tree.h"
#include "orange.h"
int Tree::tree_num_ = 0;
int class_demo() {
  Orange org("shangtangju", "Orange");
  org.setName("shatangju");
  org.printName();
  std::cout << "sizeof org: " << sizeof(org) << std::endl;
  std::cout << "is fruit tree: " << org.isFruitTree() << std::endl;
  std::cout << "height of tree: " << org.getHeight() << std::endl;
  askName(org);

  const Orange miju("xiaomiju", "Orange");
  miju.printName();
  std::cout << "num of tree is: " << Tree::getNumOfTree() << std::endl;
  return 0;
}

