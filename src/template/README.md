### 函数模板的显式定义
template<> void function<ST>(ST a, ST b) {}

### 函数模板的显式声明
template void function<ST>(ST a, ST b)；

### 类模板的显式定义
template<> typename classname<ST> {};

### 类模板的显式声明
template typename classname<ST>；
