#include<iostream>
#include "logger.h"

int main() {
  Log(INFO) << "hello, logger";
  Log(WARNING) << "WARNING TEST";
  Log(ERROR) << "ERROR TEST";
  MyLog(1) << "logger level is 1";
  MyLog(2) << "logger level is 2";
  MyLog(3) << "logger level is 3";
  std::cout << "hello logger, end" << std::endl;
  Log(FATAL) << "FATAL TEST";
  return 0;
}
