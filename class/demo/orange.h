/************************************************************************************
 *构造函数：
 *  初始化：
 *    原则上类的成员变量不应该在定义的地方初始化，因为类是数据类型，不占内存空间
 *    但c++11支持类成员在定义的地方初始化，这是因为类的实例化顺序是：
 *    先父类，再成员变量，然后初始化列表，最后调自己的构造函数。析构时与此相反（以height_为例）
 *    |    数据成员类型    |const|static|normal|
 *    |在声明时初始化      |Y    |N     |Y     |
 *    |在初始化列表中初始化|Y    |N     |Y     |
 *    |在构造函数体中初始化|N    |N     |Y     |
 *    |在类外初始化        |N    |Y     |N     |
 *  关键字：
 *    =default 显示声明这是一个默认构造函数，如果用户自己写的构造函数比默认构造函数更高效，
 *             则可以声明自己的函数为编译器默认执行的构造函数
 *    =delete  显示禁止定义某类成员函数 
 *    explict  禁止隐式转换，即禁止对象的这种赋值: cls obj_b = obj_a
 *析构函数：
 *  析构顺序：
 *    先自身，再成员变量，最后父类
 ************************************************************************************/
#include<string>
#include "tree.h"
#include "fruit.h"

class Orange : public Tree {
 public:
  // Orange(std::string name, std::string ctg); // = default; 
  Orange(std::string name, std::string ctg, float height = 1.0);
  // explict Orange(std::string name);
  Orange(Orange&) = delete;
  ~Orange();

  bool isFruitTree();
  float getHeight();

  private:
    float height_ = 0.0;
    const bool is_fruit_;
    Fruit fruit_;
};
