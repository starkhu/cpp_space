#include <iostream>
#include <time.h>
#include <stdlib.h>

void randTest() {
  int max_int = RAND_MAX;
  std::cout << "10jinzhi, max int is: " << max_int << std::endl;
  std::cout << "10jinzhi, max int is: " << std::dec << max_int << std::endl;
  std::cout << " 8jinzhi, max int is: " << std::oct << max_int << std::endl;
  std::cout << "16jinzhi, max int is: 0x" << std::hex << max_int << std::endl;
  
  int seed = (int) time(0);
  srand(seed);
  for (int i = 0; i < 10; i++) {
    std::cout << "generate 10 rand num: ";
    for (int i = 0; i < 10; i++) {
      std::cout << std::dec << rand() << " ";
    }
    std::cout << " " << std::endl;
  }
}

int main() {
  randTest();
  return 0;
}
