#include <iostream>
#include <string.h>

int testMemcpy() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 0};
  int b[20] = {0};
  memcpy(b+5, a+5, 5*sizeof(int));
  for (int i = 0; i < 10; i++) {
    std::cout << "a is: " << a[i] << std::endl;
  }
  for (int i = 0; i < 20; i++) {
    std::cout << "b is: " << b[i] << std::endl;
  }
  return 0;
}
