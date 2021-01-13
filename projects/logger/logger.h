#include<iostream>
#include<sstream>
#include<string>

#define INFO 0
#define WARNING 1
#define ERROR 2
#define FATAL 3

#define RESET      "\033[0m"
#define HIGHLIGHT  "\033[1m"
#define UNDERLINE  "\033[4m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"


class MyLogger : public std::stringstream {
 public:
  MyLogger(std::string file_path, int line_num, int severity)
    : file_path_(file_path), line_num_(line_num), severity_(severity) {}

  static int ExpectedMinLogLevel();

  void GenerateLogInfo();

  ~MyLogger();

 private:
  std::string file_path_;
  int line_num_;
  int severity_;
  std::stringstream ss_;
};

#define PREDICT_TRUE(x)  __builtin_expect(!!(x), 1)
#define PREDICT_FALSE(x) __builtin_expect(!!(x), 0)

#define Log(severity) MyLogger(__FILE__, __LINE__, severity)
#define MyLog(LEVEL)                                                   \
    if (PREDICT_FALSE(LEVEL <= MyLogger::ExpectedMinLogLevel()))       \
       MyLogger(__FILE__, __LINE__, INFO)
