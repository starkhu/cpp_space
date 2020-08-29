#include <iostream>

static int s_a = 10;

class Cls_1 {
 private:
  char a;        // sizeof: 1
  int b;         // sizeof: 8
  const int& c;  // sizeof: 16
  int* d;        // sizeof: 24
  double e;      // sizeof: 32
  static int f;  // sizeof: 32
 public:
  Cls_1(int a): c(a) {}
  void func() {return;}
  virtual void func_1() {return;}  // sizeof: +8
};

int main() {
  std::cout << "sizeof Cls_1: " << sizeof(Cls_1) << std::endl;
  return 0;
}
