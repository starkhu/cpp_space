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

