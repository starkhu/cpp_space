#include<iostream>

__attribute__ ((visibility("default"))) void caller_b();
float receive_data(float a);

void caller_b() {
    float a = -900.0;
    std::cout << "sqrt(" << a << ") is " << receive_data(a) << std::endl;
}
