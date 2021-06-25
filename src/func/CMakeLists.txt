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

#file(GLOB_RECURSE FUNC_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/call_back/call_back_no_params.cpp
#                            ${CMAKE_CURRENT_SOURCE_DIR}/size_function/size_space.cc)
#add_library(Anonymous SHARED ${DIR_LIB_SRCS})
message("************************")
message(${BASIC_SRCS})
message("************************")
add_library(funcdemo SHARED ${BASIC_SRCS})

message(${CMAKE_SOURCE_DIR}/lib)
install(TARGETS funcdemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
