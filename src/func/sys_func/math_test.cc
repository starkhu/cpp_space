/******************************************************************
 *mathExponentialOperation指数运算：
 * pow(): a^n
 * sqrt(): a^0.5
 * abs(): 整数的绝对值
 * fabs(): 浮点数的绝对值
 ******************************************************************/


#include <iostream>
#include <math.h>

void mathExponentialOperation() {
  float a = 10.5;
  float square_a = pow(a, 2);
  float sqrt_a = sqrt(a);
  float abs_a = abs(-a);
  float fabs_a = fabs(-a); 
  std::cout << "a = " << a << ", square of a = " << square_a
            << ", sqrt of a = " << sqrt_a << ", abs of -a = " << abs_a
            << ", fabs of -a = " << fabs_a << std::endl;
}

int math_demo() {
  mathExponentialOperation();
  return 0;
}
