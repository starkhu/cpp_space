#include <iostream>
#include <string>

template<typename T>
T myMax(T a, T b) {
  std::cout << "*** call template function ***" << std::endl;
  return a > b ? a : b;
}

template<>
const char* myMax<const char*>(const char* a, const char* b) {
  std::cout << "*** call Specialized template function ***" << std::endl;
  return strcmp(a, b) < 0 ? a : b; 
}

#if 1
std::string myMax(std::string a, std::string b) {
  std::cout << "*** call common function ***" << std::endl;
   return a > b ? a: b;
}
#endif

int template_function_demo() {
  int a = 10;
  int b = 20;
  std::cout << myMax(a, b) << std::endl;

  const char* c_a = "hello";
  const char* c_b = "template";
  std::cout << myMax(c_a, c_b) << std::endl;

  std::string s_a = "hello";
  std::string s_b = "String";
  std::cout << myMax(s_a, s_b) << std::endl;
  std::cout << myMax<>(s_a, s_b) << std::endl;
  return 0;
}
