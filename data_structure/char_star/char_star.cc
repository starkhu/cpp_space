/************************************************************************************
 *1 char* 默认以'\0'结尾，其ASCII值是0.
 *2 strlen(char *): 获取char* 长度
 *3 char* 转string:
 *    直接赋值
 ************************************************************************************/
#include <iostream>

void sizeCharStar() {
  char *c1 = "hello";
  std::cout << "sizeof of c1 is: " << sizeof(c1)
            << ", strlen(c1) is: " << strlen(c1)
            << ", c1 is: " << c1
	    << std::endl;
}

void convertCharStar() {
  char *c1 = "hello";
  std::string str = c1;
  std::cout << "str is: " << str
            << std::endl;
}

int main() {
  sizeCharStar();
  convertCharStar();
  return 0;
}
