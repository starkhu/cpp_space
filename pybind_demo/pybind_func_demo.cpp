#include <pybind11//pybind11.h>
namespace py = pybind11;

int add(int i, int j) {
  return i * i + j;
}

PYBIND11_MODULE(my_computer, m) {
  m.doc() = "pybind demo";
  m.def("add", &add, "add fucntion");
  m.def("adder", &add, py::arg("i"), py::arg("j"), "adder fucntion");
  m.def("add1", &add, py::arg("i") = 1, py::arg("j") = 2);
}

