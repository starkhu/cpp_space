#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<execinfo.h>

extern void dump();
extern void signal_handler(int sig);
extern int add(int num);

int main() {
  int sum = 0;
  signal(SIGSEGV, signal_handler);

  sum = add(sum);

  printf(" sum = %d \n", sum);

  return 0;
}
