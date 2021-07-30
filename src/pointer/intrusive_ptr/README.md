boost::intrusive_ptr<T>
一个侵入式的引用技术型指针，即要求T类中自己定义增加引用计数和减少引用计数的友元函数。
增加引用计数：intrusive_ptr_add_ref
减少引用计数：intrusive_ptr_release

所在的头文件:
#include <boost/intrusive_ptr.hpp>

由于boost不是c++标准库，所以需要额外安装：
sudo apt-get install libboost-all-dev
