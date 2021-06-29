add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SRCS_DIR "")
include_directories(${CMAKE_CURRENT_LIST_DIR}/status)
aux_source_directory(status STATUS_DIR)
file(GLOB_RECURSE SRCS_DIR ${CMAKE_CURRENT_LIST_DIR}/valgrind_demos/test_cases.cc)
list(APPEND SRCS_DIR ${STATUS_DIR})

message("************************")
message(${SRCS_DIR})
message("************************")

#add_library(Anonymous SHARED ${DIR_LIB_SRCS})
add_library(robostdemo SHARED ${SRCS_DIR})

message(${CMAKE_SOURCE_DIR}/lib)
install(TARGETS robostdemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
