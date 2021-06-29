#include<iostream>
#include<numeric>

template<typename T>
void PrintArray(T* arr, int num) {
  for (int i = 0; i < num; i++) {
  std::cout << *(arr+i) << " " << std::endl;
  }
  std::cout << std::endl;
}

template<typename T>
void stdIotaTest() {
  T new_arr[10];
  std::iota(new_arr, new_arr + 10, 10.1);
  PrintArray(new_arr, 10);
}

template<typename T>
void stdCopyTest() {
  T arr[] = {1,2,3.0,4,5,6,8,2};
  T new_arr[8];
  std::copy(arr, arr+8, new_arr);
  PrintArray(new_arr, 8);
}

int std_iota() {
  stdIotaTest<float>();
  stdCopyTest<float>();
  return 0;
}

