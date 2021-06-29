#include<iostream>

struct NumberList {
  int value_;
  NumberList* next_;
  explicit NumberList(int value,
      NumberList* next) {
    value_ = value;
    next_ = next;}
};
