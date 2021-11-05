
#NULL
```
/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h

#if defined (_STDDEF_H) || defined (__need_NULL)
#undef NULL>>~~~/* in case <stdio.h> has defined it. */
#ifdef __GNUG__
#define NULL __null
#else   /* G++ */                                                                                                                                                                                       
#ifndef __cplusplus
#define NULL ((void *)0)
#else   /* C++ */
#define NULL 0
#endif  /* C++ */
#endif  /* G++ */
#endif>~/* NULL not defined and <stddef.h> or need NULL.  */
#undef>~__need_NULL
```

# shared_ptr
(1)定义：更安全的定义 std::shared_ptr<int> ptr = std::make_shared<int>(10);

(2)引用计数：use_count

(3)重置当前指针指向内容：reset()

(4)获得智能指针的内置指针：get()
