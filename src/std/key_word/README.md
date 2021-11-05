# assert和static_assert

static_assert：静态断言，在编译期做的断言。常用于两个变量类型，size是否一样等判断。

assert：断言，运行时做的断言


# __attribute__
GNU的一大特色就是attribute机制。attribute可以设置函数属性，变量属性，和类型属性。

举个栗子：
```
#define TF_ATTRIBUTE_ALWAYS_INLINE __attribute__((always_inline)) // 加在函数后，编译时总是当成内联函数处理
#define TF_ATTRIBUTE_NOINLINE __attribute__((noinline))  // 编译时，不要当成内联函数处理
#define TF_ATTRIBUTE_UNUSED __attribute__((unused))  // 返回值如果没有被使用，提提示warning.
```
# 匿名函数
如果匿名函数有返回类型，则格式为[capture](parameters)→return_datatype {body}

[] 表示捕获外部变量， 

[] // 未定义变量，body内使用外部变量都是错的

[=]  // a按值捕获

[&] // 按引用捕获

[x, &y] // x按值捕获， y按引用捕获

[=, &x] // x按引用捕获，其余外部变量按值捕获
