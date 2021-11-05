#include <stdio.h>

void attribute_constructor() __attribute__((constructor));
void attribute_constructor101() __attribute__((constructor));
void attribute_constructor102() __attribute__((constructor));

void attribute_constructor() {
  printf("exec attribute constructor function\n");
}

void attribute_constructor101() {
  printf("exec attribute constructor function 101\n");
}

void attribute_constructor102() {
  printf("exec attribute constructor function 102\n");
}

void __attribute__((destructor)) attribute_destructor() {
  printf("exec attribute destructor function\n");
}

void __attribute__((destructor)) attribute_destructor101() {
  printf("exec attribute destructor function101\n");
}

void __attribute__((destructor)) attribute_destructor102() {
  printf("exec attribute destructor function 102\n");
}

int main(int argc, char** argv) {
  printf("in main function\n");
  return 0;
}

