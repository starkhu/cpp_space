#include<stdio.h>

void __attribute__((constructor)) attribute_constructor() {
  printf("exec attribute constructor function on print.c\n");
}

void print() {
  printf("hello, test\n");
}
