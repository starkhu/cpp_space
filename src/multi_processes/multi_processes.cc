#include <iostream>
#include <unistd.h>

int multi_process_demo() {
  int i = 10;
  std::cout << "flag1, pid is: " << getpid() << std::endl;
  if (fork() > 0) {
    ++i;
    std::cout << "this is father process, pid is " << getpid() << std::endl;
  } else {
    if (fork() > 0) {
    sleep(1);
    ++i;
    std::cout << "this is child process, pid is " << getpid() << std::endl;
    } else {
      sleep(1);
      std::cout << "this is childchild process, pid is " << getpid() << std::endl; 
    }
  }
  std::cout << "flag2, pid is: " << getpid() << std::endl;
  std::cout << "i is: " << i << std::endl;

}
