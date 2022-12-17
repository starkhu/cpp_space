struct结构体

### C语言和C++中在 struct 定义上的区别：
以下代码进行举例说明：

**区别1**
```
// case1
struct Student {
    char name[20];
    int age; 
} stu;
```
stu 定义的差异：
 - C语言将 stu 解释成 Student 结构体实例化生成的一个变量。
 - C++ 中将 stu 解释成数据类型，其等价于 ` struct Student`。


**区别2**
```
// case2
typedef struct Student {
    char name[20];
    int age; 
} sstu;
```
(1) 以上定义方式，在C语言和C++ 中，sstu 是 `struct Student` 的别称，都表示数据类型。

(2) C 语言中结构体的表示方式必须加上关键字 `struct`, C++ 中对该关键字可加可不加。如下例：
```
// C 语言中定义struct 结构体
struct Student s1;
sstu s2;
// C++ 中定义 struct 结构体
struct Student s1;
sstu s2;
Student s3;
```
