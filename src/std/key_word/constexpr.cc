#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<array>

constexpr int kWeeks = 7;

constexpr int FivePlus(int x) {
    return 5 + x;
}

const int OnePlus(int x) {
    return 1 + x;
}

int main() {
    srand((unsigned)time(NULL));
    int a = rand();
    int b = FivePlus(a);
    int c = FivePlus(10);
    std::array<int, FivePlus(10)> arr;
    std::cout << "FivePlus(10) is: " << b << std::endl;

    int d = OnePlus(10);
     d += 1;
    return 0;
}
