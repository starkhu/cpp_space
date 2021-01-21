#include <iostream>
#include <string>

namespace code {
enum StatusCode {
  OK = 0,
  CANCELLED = 1,
  UNKNOWN = 2,
  INVALID_ARGUMENT = 3,
  DEADLINE_EXCEEDED = 4,
  NOT_FOUND = 5,
  ALREADY_EXISTS = 6,
  PERMISSION_DENIED = 7,
  UNAUTHENTICATED = 16,
  RESOURCE_EXHAUSTED = 8,
  FAILED_PRECONDITION = 9,
  ABORTED = 10,
  OUT_OF_RANGE = 11,
  UNIMPLEMENTED = 12,
  INTERNAL = 13,
  UNAVAILABLE = 14,
  DATA_LOSS = 15,
};
}


class Status {
 public:
  Status() {set_ok();}
  Status(code::StatusCode code, std::string msg);
  static Status OK();
  bool ok() __attribute__ ((warn_ununsed_result));
  void set_ok() {code_ = code::OK;}
  std::string msg() {return msg_;}

 private:
  code::StatusCode code_;
  std::string msg_;
};

#define MUST_USE_RESULT __attribute__((warn_unused_result))
class MUST_USE_RESULT Status;


#define CHECK_STATUS(...)                  \
  do {                                     \
     Status s = __VA_ARGS__;               \
     if(!s.ok()) {                         \
       std::cerr << s.msg() << std::endl;  \
     }                                     \
  } while(0);

namespace errors {
#define DECLARE_ERROR(FUNC, CONST)         \
  template<typename Arg>                   \
  inline Status FUNC(Arg args) {           \
    return Status(CONST, args);            \
  }

DECLARE_ERROR(InvalidArgument, code::INVALID_ARGUMENT)
DECLARE_ERROR(NotFound, code::NOT_FOUND)
#undef DECLARE_ERROR
}



