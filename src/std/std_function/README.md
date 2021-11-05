# 1 accumulate
## head file
```c++
template< class InputIt, class T >
T accumulate( InputIt first, InputIt last, T init );

template< class InputIt, class T >
constexpr T accumulate( InputIt first, InputIt last, T init );

template< class InputIt, class T, class BinaryOperation>
T accumulate( InputIt first, InputIt last, T init,
              BinaryOperation op );

template< class InputIt, class T, class BinaryOperation >
constexpr T accumulate( InputIt first, InputIt last, T init,
                        BinaryOperation op );
```

# implementation:
```c++
template<class InputIt, class T, class BinaryOperation>
constexpr // since C++20
T accumulate(InputIt first, InputIt last, T init, 
             BinaryOperation op)
{
    for (; first != last; ++first) {
        init = op(std::move(init), *first); // std::move since C++20
    }
    return init;
}
```

# 2 bind
函数原型：
auto  binder_name = std::bind（fn_name, param1, param2,  ...）

简介：函数适配器，用来给现有的函数添加默认的参数，或者修改fn_name参数的放置顺序

头文件： #include<functional>

c++11新特性

param_n可以放默认参数，也可以放一个占位符，值由binder_name设置。占位符：std:placeholders::_1

binder_name中参数可以多给，多给时，会自动抛弃多余的参数。

# 2 function
std::function<type1(type2, ...)> function_name = origin_function_name // 其中，type1表示返回值数据类型，type2...表示参数的数据类型
c++11的新特性
通用的多态函数函数包装器，就是将函数（普通函数，匿名函数、类成员函数）换一种表达方式。
头文件：#include<functional>

# 3 is_base_of
(1) 判断基类与子类的关系：std::is_base_of<BaseClass, DerivedClass>::value 

栗子：static_assert(std::is_base_of<BaseClass, DerivedClass>::value，“DerivedClass should derive from BaseClass”);
