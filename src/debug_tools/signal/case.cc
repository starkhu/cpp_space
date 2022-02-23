#include<iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>

int send_interrupt_singal() {
  std::cout << "---------send interrupt signal------------" << std::endl;
  std::raise(SIGINT);
  std::cout << "---------send interrupt signal------------" << std::endl;
  return 0;
}

void abort_signal(void (*callback)(int)) {
  signal(SIGABRT, callback);  // 6

  std::cout << "Abort signal......" << std::endl;
  abort();
}

void calculate_irregular_signal(void (*callback)(int)) {
  signal(SIGFPE, callback);  // 8

  std::cout << "Arithmetic exception signal......" << std::endl;
  int a = 2;
  int b = 0;
  int c = a / b;
}
