#include<iostream>

template<typename T>
T add(T a, T b) {
  return a + b;
}


template int add<int>(int a, int b);
template float add<float>(float a, float b);
