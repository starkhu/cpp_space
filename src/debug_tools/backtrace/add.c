#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int add1(int num) {
  int ret = 0;
  int* ptr = NULL;
  *ptr = 1;
  ret = num + *ptr;

  return ret;
}

int add(int num) {
  int ret = 0;
  ret = add1(num);

  return ret;
}
