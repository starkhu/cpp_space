#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main() {
  int fd[2] = {0, 0};
  int flag = 0;
  //create pipe
  int ret = pipe(fd);
  if(ret == -1) {
    std::cerr << "creat pipe error";
    return 1;
  }
  std::cout << "fd[0] is " << fd[0]
            << ", fd[1] is " << fd[1] << std::endl;
  pid_t pid=fork();
  if(pid < 0) {
    std::cerr << "fork error" << std::endl;
    return 2;
  } else if (pid == 0) {
    std::cout << "child writing" << std::endl;
    std::cout << "in child process, addr of pipe: " << fd << std::endl;
    flag += 2;
    std::cout << "in child process, addr of flag: " << &flag
             << ", flag is: " << flag << std::endl;
    close(fd[0]);
    int count = 5;
    const char *msg = "hello, write msg to pipe";
    while (count--) {
      write(fd[1], msg, strlen(msg));
      sleep(1);
    }
    close(fd[1]);
    exit(1);
  } else {
    std::cout << "father process is reading" << std::endl;
    flag += 1;
    std::cout << "in father process, addr of pipe: " << fd << std::endl;
    std::cout << "in father process, addr of flag: " << &flag
             << ", flag is: " << flag << std::endl;
    close(fd[1]);
    char msg[1024];
    int count=5;
    while(count--) {
      ssize_t s = read(fd[0], msg, sizeof(msg)-1);
      if(s > 0) {
        msg[s] = '\0';
        std::cout << "client# " << msg << std::endl;
      } else {
        std::cerr << "read error" << std::endl;
        exit(1);
      }
    }
    if (waitpid(pid, 0, 0) != -1) {
      std::cout << "wait success" << std::endl;
    }
    close(fd[0]);
  }
  return 0;
}
