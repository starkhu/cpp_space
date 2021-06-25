#include <iostream>
#include <string>

template<typename T1, typename T2>
class MyMax {
 public:
  MyMax(T1 a, T2 b) :  a_(a), b_(b) {
    std::cout << "*** call MyMax constructor functor ***" << std::endl;
  }

  int compare_a(T1 tar) {
    return a_ > tar ? 1 : -1; 
  }

  int compare_b(T2 tar) {
    return b_ > tar ? 1 : -1; 
  }

  void print_info();

  template<typename P>
  void print_tar(P tar);

 private:
  T1 a_;
  T2 b_;
};

template<typename T1>
class MyMax<T1, std::string> {
 public:
  MyMax(T1 a, std::string b) : a_(a), b_(b) {
    std::cout << "*** call MyMax constructor functor, partial specialized ***" << std::endl;
  }

  int compare_a(T1 tar) {
    return a_ > tar ? 1 : -1; 
  }

  int compare_b(std::string tar) {
    return b_ > tar ? 1 : -1; 
  }

 private:
  T1 a_;
  std::string b_;
};

template<>
class MyMax<std::string, std::string> {
 public:
  MyMax(std::string a, std::string b) : a_(a), b_(b) {
    std::cout << "*** call MyMax constructor functor, full specialized ***" << std::endl;
  }

  int compare_a(std::string tar) {
    return a_ > tar ? 1 : -1; 
  }

  int compare_b(std::string tar);

 private:
  std::string a_;
  std::string b_;
};

template<typename T1, typename T2>
void MyMax<T1, T2>::print_info() {
  std::cout << "a: " << a_ << ", b: " << b_ << std::endl;
}

template<typename T1, typename T2>
template<typename P>
void MyMax<T1, T2>::print_tar(P tar) {
  std::cout << "a: " << a_ << ", b: " << b_ << std::endl;
  std::cout << "tar is: " << tar << std::endl;
}

int MyMax<std::string, std::string>::compare_b(std::string tar) {
  return b_ > tar ? 1 : -1; 
}


int template_class_demo() {
  float a = 10.0;
  int b = 20;
  MyMax<float, int> my_max_1(a, b);
  my_max_1.print_info();
  my_max_1.print_tar<int>(b);

  std::string s = "hello";
  MyMax<float, std::string> my_max_2(a, s);

  MyMax<std::string, std::string> my_max_3(s, s);

  return 0;
}
