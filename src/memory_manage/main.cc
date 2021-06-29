#include <iostream>
#include "memory_manage.h"
#include "memcpy.h"

int memory_manage_demo() {
  pairNewDelete();
  pairMallocFree();
  testMemcpy();
  return 0;
}
