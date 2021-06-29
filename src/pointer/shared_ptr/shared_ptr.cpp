/************************************************************************************
 *shared_ptr:
 *  make_shared<>(): 创建对象
 *  use_count: 返回引用的计数
 *  swap: 交换两个ptr指向的对象
 *  reset: 放弃对对象的所有权
 *  get: 获取对象的指针，ptr和ptr.get()是一样的
 ************************************************************************************/


#include<iostream>
#include<vector>
#include<memory>

void sptrUseCount(std::vector<std::shared_ptr<int>> sptr) {
  std::cout << "###3sptr is: " << &sptr << std::endl;
  for (int i = 0; i < sptr.size(); i++)
    std::cout << "sptr_" << i << ".use_count: "
              << sptr.at(i).use_count() << std::endl;
}

void sptrGetValue(std::vector<std::shared_ptr<int>> sptr) {
  std::cout << "value is: ";
  std::cout << "###2sptr is: " << &sptr << std::endl;
  for (int i = 0; i < sptr.size(); i++) {
    std::cout << *(sptr.at(i)) << " ";
  }
  std::cout << std::endl;
}

void getInfo(std::vector<std::shared_ptr<int>> sptr) {
  std::cout << "###1sptr is: " << &sptr << std::endl;
  sptrGetValue(sptr);
  sptrUseCount(sptr);
}

std::vector<std::shared_ptr<int>> getSptrVec(std::shared_ptr<int>* arr, int len) {
  std::cout << "###arr is: " << &arr << std::endl;
  std::vector<std::shared_ptr<int>> vec(arr, arr+len);
  std::cout << "###1sptr is: " << &vec << std::endl;
  return vec;
}

int shared_ptr_test() {
  std::shared_ptr<int> sptr_1(new int(10));
  std::shared_ptr<int> sptr_2 = std::make_shared<int>(20);
  std::shared_ptr<int> sptr_3 = sptr_2;
  std::shared_ptr<int> arr[3] = {sptr_1, sptr_2, sptr_3};
   std::cout << "&arr is: " << &arr << std::endl;
  // getInfo(getSptrVec(arr, 3));
  auto vec = getSptrVec(arr, 3);
  getInfo(vec);
  sptr_2.swap(sptr_1);
  sptr_3.reset();
  sptr_3.reset(new int(30));
  // getInfo(getSptrVec(arr, 3));
}
