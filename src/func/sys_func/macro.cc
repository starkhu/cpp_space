#include <iostream>

#define PI 3.14
#define SUM(a,b) a+b 

#define MAX(a, b) (a > b ? a : b)

#define UNIT_AREA(shape)               \
  do {                                 \
    if (shape == "circle") {           \
      std::cout << PI << std::endl;    \
    } else if ( shape == "square") {   \
      std::cout << "1" << std::endl;   \
    } else {                           \
      std::cout << "1.0" << std::endl; \
    }                                  \
  } while(0)

#define  LOG(...) {printf("%s\n", __VA_ARGS__);} 
#define  ERROR_LOG(x, ...) if (x) {printf("%s\n", __VA_ARGS__);} 


float circleArea(float r) {
  return PI * r * r;
} 


int macro_demo() {
  float a = 10;
  std::cout << circleArea(a) << std::endl;

  float b = 20;
  std::cout << "max of a and b is: " << MAX(1, 2)  << std::endl;
  std::cout << "max of a and b is: " << MAX(1.5, 2.1) << std::endl;

  std::cout << "area of rectangle: " << 2 * SUM(1, 2) << std::endl;
  
  std::cout << "area of unit area: " << std::endl;
  UNIT_AREA("circle");

  LOG("this is log")
  LOG("this is log");
  ERROR_LOG(1, "this is error log");
  {printf("log");}
  {printf("log");};

  return 0;
}
