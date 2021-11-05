#include <iostream>

void attribute_aligned() {
  struct unaligned_struct {
    short a[3];
  };
  struct aligned_struct {
    short a[3];
  } __attribute__((aligned (8)));
  struct default_aligned_struct {
    short a[3];
  } __attribute__((aligned));

  std::cout << "sizeof unaligned_struct is: " << sizeof(unaligned_struct) << std::endl;
  std::cout << "sizeof aligned_struct is: " << sizeof(aligned_struct) << std::endl;
  std::cout << "sizeof default_aligned_struct is: " << sizeof(default_aligned_struct)
            << std::endl;
}

void attribute_packed() {
  struct unpacked_struct {
    char c;
    int i;
  };
  struct packed_struct {
    char c;
    int i;
  } __attribute__((__packed__));

  std::cout << "sizeof unpacked_struct is: " << sizeof(unpacked_struct) << std::endl;
  std::cout << "sizeof packed_struct is: " << sizeof(packed_struct) << std::endl;
}





void __attribute__ ((destructor)) attribute_destructor() {
  std::cout << "exec attribute destructor function" << std::endl;
}

int main(int argc, char** argv) {
  attribute_aligned();
  attribute_packed();
  return 0;
}

