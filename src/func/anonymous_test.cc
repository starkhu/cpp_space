#include<iostream>

int anonymous() {
  int n = 10;
  auto nSquareFunc = [n](int a)->int {
    int res = a;
    for (int i = 0; i < n-1; i++) {
      res *=  a;
    }
    return res;
  };
  
  std::cout << "2^10 is: " << nSquareFunc(2) << std::endl;
  return 0;
}
