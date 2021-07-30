# 编译c++代码的流程
预处理
g++ -i main.cc -o main.i
汇编
g++ -s main.i -o main.s
汇编生成二进制文件
g++ -c main.s -o main.o
每一个.cc/.cpp文件是一个编译单元，即一个.o文件。
之后链接器可以将若干编译单元编译成静态库(.a文件)/动态库(.so文件)/可执行文件。




生成静态库：
add_library(static_library_name dir_of_src_cppcode)
生成动态库：
add_library(static_library_name SHARED dir_of_src_cppcode)
生成可执行文件
add_executable(exec_name dir_of_src_cpp_name)


## 编译选项
- add_compile_options
Adds options to the COMPILE_OPTIONS directory property. These options are used when compiling targets from the current directory and below.

- set(cmake_variable_option, cmake_variable_option)

- include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
让cmake找到通过include<>引入的头文件

> include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
把dir1, [dir2 …]这（些）个路径添加到当前CMakeLists及其子CMakeLists的头文件包含路径中;
AFTER 或者 BEFORE 指定了要添加的路径是添加到原有包含列表之前或之后
若指定 SYSTEM 参数，则把被包含的路径当做系统包含路径来处理

aux_source_directory(<dir> <variable>)
查找dir路径下的所有源文件，保存到variable变量中.

link_directories(directory1 directory2 ...)
添加库路径, 告诉编译器这个路径下有需要链接的库
相当于添加环境变量LD_LIBRARY_PATH的作用。想当于g++命令中的-L选项

target_link_directories(<target> ...<item>... ...)
target是一个可执行文件，or动态库， or静态库
item是target依赖的库/库列表

what is difference between link_directories and target_link_directories():
link_directories只是告诉CMake这个位置可能有lib，而target_link_libraries是真正地要CMake去生成target。
所以可见区别有二:
1）link_directories输入的是path，而target_link_libraries输入的是二进制文件名或着已经生成但未link的target；
2）target_link_libraries需要指定target并且调用linker，link_directories不指定target


- message(str_msg)
编译期间的打印信息

- add_sublibrary(source_dir [binary_dir] [exclude_from_all])
添加一个子目录，并构建该子目录
如果source_dir不是当前目录的子目录，这时需要binary_dir设置source_dir目录


### abi
使用新的abi接口，默认使用新的abi
g++ demo.cc -o d0 --std=c++11


使用旧的abi.
g++ demo.cc -o d0 --std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0

通过objdump可以查看函数对应的符号。
objdump -t  | grep "set_str"

如下：
```
#新版接口
0000000000400c21 g     F .text  000000000000002b              _Z7set_strNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
0000000000400bf6 g     F .text  000000000000002b              _Z15set_unorder_mapSt13unordered_mapIiiSt4hashIiESt8equal_toIiESaISt4pairIKiiEEE
#旧版接口
0000000000400b71 g     F .text  000000000000002b              _Z7set_strSs
0000000000400b46 g     F .text  000000000000002b              _Z15set_unorder_mapSt13unordered_mapIiiSt4hashIiESt8equal_toIiESaISt4pairIKiiEEE
```
通过c++filt可以翻译上述symb,得到如下函数签名：
```
// 新版std::string函数签名：
set_str(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
// 旧版std::string函数签名
set_str(std::basic_string<char, std::char_traits<char>, std::allocator<char> >)
```
