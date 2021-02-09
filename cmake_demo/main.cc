#include <iostream>
#include "math/math.h"
int main() {
#ifdef TEST_ENV
  int a = 1;
#else
  int a = 2;
#endif
  std::cout << add(a, 1) << std::endl;
}
