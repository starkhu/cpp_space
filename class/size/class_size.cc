#include<iostream>

class NullClass {};

class BaseC {
  int a;
  char b;
  int c;
  int d;
};

class DeriveC1 : public BaseC {
  virtual void VirtualFunc() {};
};

class DeriveC2 : public BaseC {
  virtual void VirtualFunc1() {};
};

class DeriveD1 : public DeriveC1 {};

class DeriveD2 : public DeriveC1, public DeriveC2 {};


int class_size() {
  std::cout << "size of NullClass is: " << sizeof(NullClass) << std::endl;
  std::cout << "size of BaseC is: " << sizeof(BaseC) << std::endl;
  std::cout << "size of DeriveC1 is: " << sizeof(DeriveC1) << std::endl;
  std::cout << "size of DeriveD1 is: " << sizeof(DeriveD1) << std::endl;
  std::cout << "size of DeriveD2 is: " << sizeof(DeriveD2) << std::endl;
  return 0;
}
