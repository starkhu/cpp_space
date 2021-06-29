#include<iostream>                                                                                                                                                                                          
#define GREEN "\033[32m"
#define BGREEN "\033[1m\033[32m"
#define BRED "\033[1m\033[31m"
#define BWHITE "\033[0m\033[37m"
int main() {
  std::cout << BGREEN << "bgreen color, "
            << GREEN << "green color, "
            << BRED << "red color, "
            << BWHITE<< "white color"
            << std::endl;
  return 0;
}

