#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(BASIC_SRCS "")
aux_source_directory(. DIR_LIB_SRCS)
aux_source_directory(call_back CALL_BACK_DIR)
aux_source_directory(sys_func SYS_FUNC_DIR)
list(APPEND BASIC_SRCS ${DIR_LIB_SRCS})
list(APPEND BASIC_SRCS ${CALL_BACK_DIR})
list(APPEND BASIC_SRCS ${SYS_FUNC_DIR})

add_library(funcdemo SHARED ${BASIC_SRCS})

install(TARGETS funcdemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
