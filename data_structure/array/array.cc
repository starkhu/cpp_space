/****************************************************************************
 *数组地址：
 *    对于二维数组，arr, &arr, arr[0]都是数组的首地址
 *数组的初始化：
 *    1）常规的初始化，a[n] = {}
 *    2）指针的初始化，int *p = new int[n]()
 *    3）c++11中中间的等号可以省略
 *    4）缺省的值，数组默认只会补零
 *sizeof(arr)是数组所占空间大小，不是指针大小，其中arr是数组定义的地方
 ****************************************************************************/
#include <iostream>
#include <string>
#define CPP11 0
void testAddrArr() {
  int arr[2][3] = {1, 2, 3, 4, 5, 6};
  std::cout << "arr is: " << arr << std::endl;
  std::cout << "&arr is: " << &arr << std::endl;
  std::cout << "arr[0] is: " << arr[0] << std::endl;
  std::cout << "arr[1] is: " << arr[1] << std::endl;
  
  std::cout << "sizeof arr: " << sizeof(arr) << std::endl;
}

template <typename T>
static void printArray (T *arr, int cnt, std::string name="arr") {
  std::cout << name << "[" << cnt << "] = {";
  for (int i = 0; i < cnt; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "}" << std::endl;
}

void initArray() {
  int arr1[5] = {1, 2, 3};
  int arr2[5] = {0};
  int arr3[5] = {1};
#ifdef CPP11
  int arr4[5]{};
  int arr5[5]{1};
  int arr6[5]{1, 2, 3, 4, 5};
#endif  // CPP11

  int *arr7 = new int[5];
  int *arr8 = new int[5]{1};
  printArray(arr1, 5, "arr1");
  printArray(arr2, 5, "arr2");
  printArray(arr3, 5, "arr3");
#ifdef CPP11
  printArray(arr4, 5, "arr4");
  printArray(arr5, 5, "arr5");
  printArray(arr6, 5, "arr6");
#endif  // CPP11
  printArray(arr7, 5, "arr7");
  printArray(arr8, 5, "arr8");
}

int main() {
  testAddrArr();
  initArray();
  return 0;
}
