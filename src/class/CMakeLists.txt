add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SRCS_DIR "")
include_directories(${CMAKE_CURRENT_LIST_DIR}/demo)
aux_source_directory(demo DEMO_DIR)
file(GLOB_RECURSE SRCS_DIR ${CMAKE_CURRENT_LIST_DIR}/size/class_size.cc)
list(APPEND SRCS_DIR ${DEMO_DIR})

message("************************")
message(${SRCS_DIR})
message("************************")

add_library(classdemo SHARED ${SRCS_DIR})

message(${CMAKE_SOURCE_DIR}/lib)
install(TARGETS classdemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
