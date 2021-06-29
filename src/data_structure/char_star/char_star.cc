/************************************************************************************
 *1 char*, char[] 默认以'\0'结尾，其ASCII值是0.
     多维char[][]: 仅第一维度可以缺省
 *2 strlen(char *): 获取char* 长度
 *3 char* 转string:
 *    直接赋值
 ************************************************************************************/
#include <iostream>
#include <string.h>
#include "char_star_function.h"

void sizeCharStar() {
  const char *c1 = "hello";
  char c2[6] = "hello";
  std::cout << "sizeof of c1 is: " << sizeof(c1)
            << ", strlen(c1) is: " << strlen(c1)
            << ", c1 is: " << c1
            << std::endl;
}

void convertCharStar() {
  const char *c1 = "hello";
  std::string str = c1;
  std::cout << "str is: " << str
            << std::endl;
}

int char_star() {
  // sizeCharStar();
  // convertCharStar();
  // strcpyTest();
  // memcpyTest();
  strncpyTest();
  return 0;
}
