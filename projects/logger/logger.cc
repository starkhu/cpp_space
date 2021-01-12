#include<iostream>
#include<stdio.h>
#include<sstream>
#include<string>

class MyLogger : public std::stringstream {
 public:
  MyLogger(std::string file_path, int line_num)
    : file_path_(file_path), line_num_(line_num) {}
  void GenerateLogInfo() {
    fprintf(stderr, "%s %d, %s\n", file_path_.c_str(), line_num_,
        str().c_str());
  }
  ~MyLogger() {
    GenerateLogInfo();
  }
 private:
  std::string file_path_;
  int line_num_;
};

#define Log MyLogger(__FILE__, __LINE__)

int main() {
  Log << "hello, logger";
  return 0;
}
