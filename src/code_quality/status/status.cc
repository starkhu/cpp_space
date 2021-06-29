#include<iostream>
#include "status.h"

Status::Status(code::StatusCode code, std::string msg)
  : code_(code), msg_(msg) {}

bool Status::ok() {
  if (code_ == code::OK) return true;
  return false;
}

Status Status::OK() {return Status();}
