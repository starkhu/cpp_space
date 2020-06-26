

## strcpy、strncpy与memcpy的区别与使用方法

### memcpy函数
  - void  *memcpy(void *dst,  const void *src,  size_t  n);

### strcpy函数
  - char  *strcpy(char *s2, const char *s1);

### strncpy函数
  - char  *strncpy(char *s2, const char *s1, size_t n);

如果s1指向的数组是一个比n短的字符串，则在s2定义的数组后面补空字符，直到写入了n个字符。

strcpy 是依据 “\0” 作为结束判断的，如果 s2 的空间不够，则会引起 buffer overflow。

memcpy用来在内存中复制数据，由于字符串是以“\0”结尾的，所以对于在数据中包含“\0”的数据只能用memcpy，如:"hell\0oworld"。

Strncpy和memcpy很相似，只不过它在一个终止的空字符处停止。当n>strlen(s1)时，给s2不够数的空间里填充“\0”；当n<=strlen(s1)时，s2是没有结束符“\0”的。
