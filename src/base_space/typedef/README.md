#typedef

typedef 用于一个给数据类型起别名，这个数据类型可以是如下几类：
- int、float等常见的数据类型
- 枚举类型
- 结构体
- 函数指针
以下结合实例一一说明其用法。

### 给数据类型起别名
（1）最简单的应用示例：常见的数据类型如int、float等，可将该数据类型换个别名。此类用法在实际编程中的应用场景较少。

     如下例，可用NUM变量表示int类型变量。
```
typedef int NUM;
```

（2）增加代码的可移植性、可阅读性：一些不常见的变量在不同的系统上表示的含义不同。如果获取一个稳定的数据类型，可自行定义新变量表示。

     case1: 如表示8字节的整数，在32位的操作系统中其数据类型为 `long long int`, 在64位的操作系统中其数据类型为 `long int`。如果想要一个64类型的正整数，则可以使用如下实现：

```
#if __WORDSIZE == 64
    typedef long int int64_t;
#else
    typedef long long int int64_t;
#endif
```
   case2: 表示8字节的正整数类型size_t，其真实的数据类型在<stddef.h>定义为：

```
#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ long unsigned int
#endif
#if !(defined (__GNUG__) && defined (size_t))
typedef __SIZE_TYPE__ size_t;
#ifdef __BEOS__
typedef long ssize_t;
#endif /* __BEOS__ */
#endif /* !(defined (__GNUG__) && defined (size_t)) */
```


###  给枚举类型起别名
如果函数返回值为枚举类型，此时需要给返回值起一个别名，方便进行函数定义,如下例：
假设表示状态的枚举值有如下：{SUCCESS, FAILED, TIMEOUT}，函数返回值为状态值，实现如下:
```
typedef enum {
  SUCCESS,                                                                                     
  FAILED,
  TIMEOUT,
} Status_t;

Status_t func() {
  ...
  return SUCCESS;
}
```


### 给结构体起别名
C语言和C++语言在struct定义这块有区别。TBD
```
// 在 C 语言中
struct Student {
  int id;
  char* name;
} Stu;
```
```
typedef struct {}
```

### 给函数指针起别名
在回调函数中常常需要将函数指针作为另一个函数的输入参数。此时需要对作为入参的函数格式进行约束，可借助 typedef 对函数起一个别名，增加可读性。

case1: 假设入参函数格式为：输入为空，返回值为void；
```
// 写法1
typedef int (*pfunc1)();
void callback_func(pfunc1 func1);
// 写法2
void callback_func(int (*pfunc1)());
```

case2: 假设入参函数格式为：输入为(float, int)，返回值为(int)；
```
// 写法1
typedef int (*pfunc2)(float, int);
void callback_func(pfunc2 func2) {
  float float_value;
  int int_value;
  func2(float_value, int_value);
}
// 写法2
void callback_func(int (*pfunc2)(float, int)) {
  float float_value;
  int int_value;
  pfunc2(float_value, int_value);
}
```

case3: 假设入参函数格式为：输入为(float, int)，返回值为函数，函数的数据类型：int func(float)
```
// 写法1
void callback_func(int (* (*pfunc3)(float, int))(float)) {
  float float_value;
  int int_value;
  pfunc3(float_value, int_value);
}
// 写法2
typedef int (* (*pfunc3)(float, int))(float);
void callback_func(pfunc3 func3) {
  float float_value;
  int int_value;
  func3(float_value, int_value);
}
// 写法3
typedef int (*pfunc)(float);
typedef pfunc (*pfunc1)(float, int);
```

### 参考资料：
> https://blog.csdn.net/hai008007/article/details/80651886
