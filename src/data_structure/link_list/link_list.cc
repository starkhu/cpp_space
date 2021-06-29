#include<iostream>
#include "link_list.h"

// NumberList* pHead = nullptr;
// NumberList* pTail = nullptr;
NumberList* AddNode(int value, NumberList* pHead) {
  if (pHead == nullptr) {
    NumberList* node = new NumberList(value, nullptr);
    std::cout << "add value to head: " << value << std::endl;
    pHead = node;
  } else {
    NumberList* node = new NumberList(value, pHead);
    std::cout << "add value to head: " << value << std::endl;
    pHead = node;
  }
  return pHead;
}

void DestroyList(NumberList* pHead) {
  NumberList* pPrev = nullptr;
  NumberList* pCurrent = pHead;
  while(pCurrent != nullptr) {
    pPrev = pCurrent;
    pCurrent = pCurrent->next_;
    std::cout << "destroy value: " << pPrev->value_ << std::endl;
    delete pPrev;
  }
}

void PrintList(NumberList* pHead) {
  while (pHead != nullptr) {
    std::cout << "value is " << pHead->value_ << std::endl;
    pHead = pHead->next_;
  }
}

NumberList* RevertList(NumberList* pHead) {
  if (pHead == nullptr) return nullptr;
  NumberList* pPrev = nullptr;
  NumberList* pCurrent = pHead;
  NumberList* pNext = pHead->next_;
  pCurrent->next_ = nullptr;
  while (pNext != nullptr) {
    std::cout << "current value is: " << pCurrent->value_ << std::endl;
    pPrev = pCurrent;
    pCurrent = pNext;
    pNext = pCurrent->next_;
    pCurrent->next_ = pPrev;
  }
  //pHead = pCurrent;
  return pCurrent;
}

int link_list_demo() {
  NumberList* phead = new NumberList(0, nullptr);
  phead = AddNode(1, phead);
  phead = AddNode(2, phead);
  phead = AddNode(3, phead);
  PrintList(phead);

  phead = RevertList(phead);
  PrintList(phead);

  DestroyList(phead);
  return 0;
}
