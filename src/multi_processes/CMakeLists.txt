#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB_RECURSE BASIC_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/multi_processes.cc)

add_library(multiprocesses SHARED ${BASIC_SRCS})

install(TARGETS multiprocesses DESTINATION ${CMAKE_SOURCE_DIR}/lib)
