#include<iostream>

#if __WORDSIZE == 64
    typedef long int int64_t;
#else
    typedef long long int int64_t;
#endif

typedef enum {
  SUCCESS,
  FAILED,
  TIMEOUT,
  BLOCKED,
  OUTOFMEMORY,
} Status_t;
