#include <iostream>

int add(int a, int b) {
  return a + b;
}

int sub(int a, int b) {
  return a - b;
}

int mul(int a, int b) {
  return a * b;
}

typedef int (*callback)(int, int);
void calculate_1(int a, int b, callback cb) {
  std::cout << cb(a, b) << std::endl;
}

void calculate_2(int a, int b, int (*callback)(int a, int b)) {
  std::cout << callback(a, b) << std::endl;
}

int call_back_demo_simple() {
  calculate_1(1, 2, add);
  calculate_2(1, 2, sub);
  return 0;
}

