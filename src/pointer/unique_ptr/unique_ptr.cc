#include <iostream>
#include <memory>


int unique_ptr() {
  std::unique_ptr<float> uq_ptr1(new float(1.0));
  std::unique_ptr<float> uq_ptr2(new float(2.0));
  // uq_ptr1.reset(new float(10.0));
  uq_ptr1.reset(std::move(uq_ptr2.get()));
  std::cout << "ptr1 is: " << *uq_ptr1 << std::endl;
  return 0;
}
