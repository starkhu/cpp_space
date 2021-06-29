# c++ string类：

## 相较于char*的优势：
  - 和char * 比较起来，string不必担心内存是否足够、字符串长度等等，
  - 作为一个类出现，其集成的函数足以完成我们大多数情况下的需要。



## 构造函数
    a) string s;    //生成一个空字符串s
    b) string s(str) //拷贝构造函数 生成str的复制品
    c) string s(str,stridx) //将字符串str内“始于位置stridx”的部分当作字符串的初值
    d) string s(str,stridx,strlen) //将字符串str内“始于stridx且长度顶多strlen”的部分作为字符串的初值
    e) string s(cstr) //将C字符串作为s的初值
    f) string s(chars,chars_len) //将C字符串前chars_len个字符作为字符串s的初值。
    g) string s(num,c) //生成一个字符串，包含num个c字符
    h) string s(beg,end) //以区间beg;end(不包含end)内的字符作为字符串s的初值
    i) s.~string() //销毁所有字符，释放内存

## 字符操作函数
    a) =,assign()     //赋以新值
    b) swap()     //交换两个字符串的内容
    c) +=,append(),push_back() //在尾部添加字符
    d) insert() //插入字符
    e) erase() //删除字符
    f) clear() //删除全部字符
    g) replace() //替换字符
    h) + //串联字符串
    i) ==,!=,<,<=,>,>=,compare()    //比较字符串
    j) size(),length()    //返回字符数量
    k) max_size() //返回字符的可能最大个数
    l) empty()    //判断字符串是否为空，是空时返回ture，不是空时返回false
    m) capacity() //返回重新分配之前的字符容量
    n) reserve() //保留一定量内存以容纳一定数量的字符
    o) [ ], at() //存取单一字符
    p) >>,getline() //从stream读取某值
    q) <<    //将谋值写入stream
    r) copy() //将某值赋值为一个C_string
    s) c_str() //将内容以C_string返回
    t) data() //将内容以字符数组形式返回
    u) substr() //返回某个子字符串
    v) 查找函数
    w) begin() end() //提供类似STL的迭代器支持
    x) rbegin() rend() //逆向迭代器
    y) get_allocator() //返回配置器

## int与string的互转：
int2string: s-'0'
string2int:  std::to_string(int_value)

