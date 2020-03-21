/************************************************************************************
 *=default 显示声明这是一个默认构造函数，如果用户自己写的构造函数比默认构造函数更高效，
 *         则可以声明自己的函数为编译器默认执行的构造函数
 *=delete  显示禁止定义某类成员函数 
 *explict  禁止隐式转换，即禁止对象的这种赋值: cls obj_b = obj_a
 ************************************************************************************/


#include<string>

class Orange {
 public:
  Orange(); // = default; 
  // explict Orange(std::string name);
  Orange(Orange&) = delete;
  void setName(std::string name);
  void printName();

  private:
    std::string name_;
    float age_;
};
