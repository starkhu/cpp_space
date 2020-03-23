/****************************************************************************
 *1 malloc和new的区别：
 *  new/delete是操作符，malloc/free是函数
 *  new/delete除了负责分配销毁地址空间，还调用对象的构造/析构函数，
 *  malloc/free只负责分配销毁一片地址。
 *2 垂悬指针：
 *  当一个指针被delete或者free,指针指向的内存区域并不会被清空，因为这会占用
 *  cpu周期，所以在delete，free操作后，仍然能打印指针指向的内容（可能是乱码）。
 *  即垂悬指针，也称野指针。
 *  所以delete, free后，需要将指针指向空，避免野指针的存在。
 ****************************************************************************/


#include <iostream>

#ifdef LINUX_OS
#include <malloc.h>
#endif

#ifdef LINUX_OS
// used for linux os
void printMallocUsableSize() {
  int *a = new int(1);
  std::cout << "MUS a is: " << malloc_usable_size(a) << std::endl;
  int *b = (int*) malloc(sizeof(int) * 8);
  std::cout << "MUS b is: " << malloc_usable_size(b) << std::endl;
  int *c = (int*) malloc(sizeof(int) * 10);
  std::cout << "MUS c is: " << malloc_usable_size(c) << std::endl;
  int *d = (int*) malloc(sizeof(int) * 20);
  std::cout << "MUS d is: " << malloc_usable_size(d) << std::endl;
}
#endif  // LINUX_OS

void pairNewDelete() {
  float *ptr1 = new float(1);
  float *ptr2 = new float[5];
  float *ptr3 = new float[5]();
  std::cout << "*ptr1 is: " << *ptr1 << std::endl;
  std::cout << "ptr3[0] is: " << ptr3[0] << std::endl;
  delete ptr1;
  std::cout << "after delete, *ptr1 is: " << *ptr1 << std::endl;
  delete []ptr2;
  delete []ptr3;
  ptr1 = nullptr;
  ptr2 = nullptr;
  ptr3 = nullptr;
}

void pairMallocFree() {
  float *ptr1 = (float *)malloc(sizeof(float));
  float *ptr2 = (float *)malloc(sizeof(float) * 2);
  *ptr1 = 1;
  ptr2[0] = 2;
  std::cout << "*ptr1 is: " << *ptr1 << std::endl;
  std::cout << "ptr2[0] is: " << ptr2[0] << std::endl;
  free(ptr1);
  std::cout << "afer free, *ptr1 is: " << *ptr1 << std::endl;
  free(ptr2);
  ptr1 = NULL;
  ptr2 = NULL;
}




int main() {
  pairNewDelete();
  pairMallocFree();
  return 0;
}






