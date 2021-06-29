#include <stdio.h>
#include <iostream>
using namespace std;

#define  OUTPUT(A) cout<<A<<":"<<(A)<<endl;
#define  LINK(a, b)  a##b
#define  TOSTRING(a) #a

#define  UNKNOWN_ARGS1(...) {printf("%s\n", __VA_ARGS__);}
#define  UNKNOWN_ARGS2(x, ...) if (x) {printf("%s\n", __VA_ARGS__);}



int macro_demo() {
    int a=1,b=2;
    int ab = 3;

    OUTPUT(a);
    OUTPUT(b);
    OUTPUT(a+b);

    // ##
    std::cout << LINK(a, b) << std::endl;
    std::cout << LINK(12, 34) << std::endl;

    // #
    std::string str = TOSTRING(2021);
    std::cout << str << std::endl;

    // ... __VA_ARGS__
    UNKNOWN_ARGS1("this is log");
    UNKNOWN_ARGS1("this is log");
    UNKNOWN_ARGS2(1, "this is  another log");

    {printf("log");}
    {printf("log");};

    return 0;
}
