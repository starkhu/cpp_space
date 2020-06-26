/************************************************************************************
 *1 sizeof(str)
 *    大小总是24，其他系统可能是其他值，但都是固定值，
 *    string是一个类，类内有一个指针用于指向string对象的内存
 *2 str.size() || str.length()
 *    储存字符串内容的内存大小
 *3 str与char *的转换
 *    str.data()
 *    str.c_str()
 *    str.copy(T* addr, int len, int start_index)
 ************************************************************************************/


#include <iostream>

void strSize() {
  std::string str = "hello, how are you, long time no see";
  std::cout << "strlen of str: " << str.length()
            << std::endl;
  std::cout << "size of str: " << str.size()
            << std::endl;
  std::cout << "sizeof of str: " << sizeof(str)
            << std::endl;
}

void convertString() {
  std::string str = "hello";
  std::cout << "&str is: " << &str
            << ", str.data() is: " << str.data()
	    << std::endl;
  const char *c1 = str.data();
  const char *c2 = str.data();
  const char *c3 = str.c_str();
  char c4[10];
  str.copy(c4, 5, 0);
  *(c4+5) = '\0';
  std::cout << "c1 is: " << c1
            << ", &c1 is: " << &c1
	    <<std::endl;
  std::cout << "c2 is: " << c2
            << ", &c2 is: " << &c2
	    <<std::endl;
  std::cout << "c3 is: " << c3
            << ", &c3 is: " << &c3
	    <<std::endl;
  std::cout << "c4 is: " << c4
            << ", &c4 is: " << &c4
	    <<std::endl;
}

//substr()
void subStr() {
  std::string str = "helloworld";
  std::string sub_str = str.substr(0, 5);
  std::cout << "str: " << str << ", sub_str: " << sub_str << std::endl;
}

//"a" +"b" -> "ab"
void concatStr() {
  std::string str_a = "a";
  std::string str_b = "b";
  std::string str = str_a + str_b;
  std::cout << "a, b, ab: " << str_a << ", " << str_b << ", " << str << std::endl;
}

int main() {
  // strSize();
  // convertString();
  subStr();
  concatStr();
  return 0;
}
