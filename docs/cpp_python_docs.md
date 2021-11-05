cpp和python的区别：
## (一)：赋值

**cpp**

 - cpp中赋值默认是深拷贝。参考case1中的b=a。
 - 如果想要对变量进行引用，需要显式操作。 参考case1中的变量c。

**python**

 - python中的赋值默认的是浅拷贝。参考case2中的b=a。
 - var = new_value的执行过程不是获取var变量的地址，然后将该地址中的值替换成new_value，而是新申请一块内存存放new_value，然后将var指向这块新申请的内存。参考case2中a的两次赋值
 - 如果一个常量赋值给两个变量，脚本中和手动敲打的处理方式不一样，猜测有可能和脚本运行时的一项优化，参考case2和case3中的a/c的的赋值。
 - Special treatment：python会[-5, 256]中的整数预先分配到一块内存变成全局变量，如果ython中的变量是这其中的值，则变量都会指向预分配的内存中该值的位置。参考case2中的d/e/f/g的赋值

### 代码：
```
// case1
#include<iostream>

int main() {
  int a = 1;
  std::cout << &a << std::endl;
  a = 2;
  std::cout << &a << std::endl;
  int b = a;
  std::cout << &b << std::endl;
  int& c = a;
  std::cout << &c << std::endl;
  return 0;
}
打印结果：
&a is: 0x7ffe71abc2f8
&a is: 0x7ffe71abc2f8
&b is: 0x7ffe71abc2fc
&c is: 0x7ffe71abc2f8
```

```
# case2
a = 1.5
b = a
c = 1.5
print("id(a) is: ", id(a))
print("id(b) is: ", id(b))
print("id(c) is: ", id(c))
a = 2.5
print("after do a=2.5 operation, id(a) is: ", id(a))

d = -5; e = -5
f = 256; g = 256 
print(f"id(d) is: {id(d)}, id(e) is: {id(e)}")
print(f"id(f) is: {id(f)}, id(g) is: {id(g)}")
打印结果：
id(a) is:  139626976460920
id(b) is:  139626976460920
id(c) is:  139626976460920
after do a=2.5 operation, id(a) is:  139626976461088
id(d) is: 9297184, id(e) is: 9297184
id(f) is: 9305536, id(g) is: 9305536

#case3
>>> a = 1.5
>>> c = 1.5
打印结果：
>>> id(a)
140381277139064
>>> id(c)
140381277139280
```
