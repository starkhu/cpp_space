#include<iostream>
#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sstream>
#include<string>
#include<map>
#include "logger.h"

namespace {
  std::map<int, std::string> severity_map = {
      {INFO,    " INFO  "},
      {WARNING, "WARNING"},
      {ERROR,   " ERROR "},
      {FATAL,   " FATAL "}
  };

  std::map<int, std::string> severity_color = {
      {INFO,    YELLOW},
      {WARNING, GREEN},
      {ERROR,   RED},
      {FATAL,   RED}
  };

  std::string GetTime() {
    struct tm *current_time;
    time_t lt;
    char timebuf[30];
    lt=time(&lt);
    current_time = localtime(&lt);
    strftime(timebuf, 30, "%Y-%m-%d %H:%M:%S", current_time);
    std::string timebuf_str = timebuf;
    return timebuf_str;
  }
}


void MyLogger::GenerateLogInfo() {
  int pid = getpid();
  int tid = syscall(SYS_gettid);
  // fprintf(stderr, "%c %s:%d] [%d] %s\n", "IWEF"[severity_], file_path_.c_str(), line_num_,
  //     thread_id, str().c_str());
  ss_ << "["  << HIGHLIGHT << severity_color[severity_] << severity_map[severity_] << RESET << "]"
      << " [" << GetTime()
      << " "  << file_path_
      << ":"  << line_num_ << "]"
      << " [" << tid << "]"
      << " "  << this->str();
  std::cerr << ss_.str() << std::endl;
}

int MyLogger::ExpectedMinLogLevel() {
  char* log_level = getenv("MY_MIN_LOG_LEVEL");
  if (log_level == nullptr) return 0;
  std::string log_level_str(log_level, strlen(log_level));
  std::stringstream ss;
  ss << log_level_str;
  int level = 0;
  ss >> level;
  return level;
}

MyLogger::~MyLogger() {
  GenerateLogInfo();
  if (severity_ == FATAL) abort();
}

