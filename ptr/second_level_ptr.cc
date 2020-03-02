#include<iostream>

void ptrFunction(int* ptr) {
  std::cout << "in ptrFunction,   ptr is: " << ptr << std::endl;
  std::cout << "in ptrFunction,   &ptr is: " << &ptr << std::endl;
  int* a = new int(1);
  std::cout << "    ptr is: " << ptr << std::endl;
  ptr = a;
}

void ptrFunction2(int** ptr) {
  std::cout << "in ptrFunction2,   ptr is: " << ptr << std::endl;
  std::cout << "in ptrFunction2,  *ptr is: " << *ptr << std::endl;
  std::cout << "in ptrFunction2, **ptr is: " << **ptr << std::endl;
  int* a = new int(2);
  *ptr = a;
}

int main() {
  int a = 10;
  int* ptr_a = &a;
  std::cout << "in main, addr of a is: " << &a << std::endl;
  std::cout << "    in main, ptr_a is: " << ptr_a << std::endl;
  std::cout << "   in main, &ptr_a is: " << &ptr_a << std::endl;

  ptrFunction(ptr_a);
  std::cout << "in main, after ptrFunction , *ptr_a is: " << *ptr_a << std::endl;

  ptrFunction2(&ptr_a);
  std::cout << "in main, after ptrFunction2, *ptr_a is: " << *ptr_a << std::endl;

  delete ptr_a;
  return 0;
}

