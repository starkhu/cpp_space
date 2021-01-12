#include<iostream>
#include<sstream>

int main() {
  std::stringstream ss;
  ss << "hello" << ", stream" << ",  123";
  std::cout << ss.str() << std::endl;
  return 0;

}
