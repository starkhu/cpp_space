constexpr
 - 修饰一个变量时，表示编译期就可以获取到的常量。
 - 修饰一个函数返回值时，表示函数返回值是一个常量。

适用于constexpr而不适用于const的场景：
arr对象需要在编译期就需要知道分配多大的内存空间，因此此时只适用于constexpr修饰的返回函数。
```
    std::array<int, FivePlus(10)> arr;
```
