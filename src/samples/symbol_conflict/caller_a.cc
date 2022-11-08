#include<iostream>

//__attribute__ ((visibility("default"))) void caller_a();
float receive_data(float a);

void caller_a() {
    float a = 100.0;
    std::cout << "sqrt(" << a << ") is " << receive_data(a) << std::endl;
}
