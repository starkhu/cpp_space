#include <pybind11/pybind11.h>
#include <iostream>

class PyBindDemo {
  public:
    PyBindDemo() {}

    void print_msg() {
      std::cout << "print" << std::endl;
    }

    void print_num(int n = 1) {
      std::cout << "hello, " << n << std::endl;
    }

    void print_str(std::string str = "pybind") {
      std::cout << "hello, " << str << std::endl;
    }

};

PYBIND11_MODULE(class_module, m) {
  pybind11::class_<PyBindDemo>(m, "PyBindDemo")
      .def(pybind11::init<>())
      .def("print_msg", &PyBindDemo::print_msg)
      .def("print_num", &PyBindDemo::print_num)
      .def("print_str", &PyBindDemo::print_str);
}
