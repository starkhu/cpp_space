#include<iostream>
#include "status.h"

Status TestCase_OK() {
  return Status::OK();
}
Status TestCase_InvalidArgument() {
  return errors::InvalidArgument("invalid argument case");
}

int status_demo() {
  TestCase_OK();
  CHECK_STATUS(TestCase_InvalidArgument());
}