##宏定义的展开
... VA_ARGS  # ## __COUNTER__
## 的用法（注意点）
当宏参数是另一个宏的时候
需要注意的是凡宏定义里有用'#'或'##'的地方宏参数是不会再展开.
1, 非'#'和'##'的情况
#define TOW(2)
#define MUL(a,b) (a*b)
printf("%d*%d=%d\n", TOW, TOW, MUL(TOW,TOW));
这行的宏会被展开为：
printf("%d*%d=%d\n", (2), (2), ((2)*(2)));
MUL里的参数TOW会被展开为(2).
2, 当有'#'或'##'的时候
#define A(2)
#define CONS(a,b)int(a##e##b)
这行会被展开为：
printf(“%s\n”, CONS(A, A));// compile error
这一行则是：printf("%s\n", int(AeA));
INT_MAX和A都不会再被展开, 然而解决这个问题的方法很简单. 加多一层中间转换宏. 加这层宏的用意是把所有宏的参数在这层里全部展开, 那么在转换宏里的那一个宏(_STR)就能得到正确的宏参数.
#define A(2)
#define _CONS(a,b)int(a##e##b)
#define CONS(a,b)_CONS(a,b)// 转换宏
printf("%d\n", CONS(A, A));
输出为：200
CONS(A, A)-->_CONS((2), (2))--> int((2)e(2))
