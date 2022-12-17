#include<stdio.h>

struct tagStudent {
   char name[20];
   int age;
} s;

int main() {
   struct tagStudent s1;
   s.age = 10;
   s1.age = 10;
   printf("s age: %d\n", s.age);
   printf("s1 age: %d\n", s1.age);

  return 0;
}
