#include<iostream>
#define FLAG 1

void testFunction(){
  #if FLAG
  #ifdef TEST
  std::cout << "define flag" << std::endl;
  #endif
  #endif
  std::cout << "test completed" << std::endl;
}

int macro_func() {
  testFunction();
}



