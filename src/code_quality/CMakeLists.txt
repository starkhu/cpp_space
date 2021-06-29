add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SRCS_DIR "")
include_directories(${CMAKE_CURRENT_LIST_DIR}/status)
include_directories(${CMAKE_CURRENT_LIST_DIR}/logger)
aux_source_directory(status STATUS_DIR)
aux_source_directory(logger LOGGER_DIR)
file(GLOB_RECURSE SRCS_DIR ${CMAKE_CURRENT_LIST_DIR}/valgrind_demos/test_cases.cc)
list(APPEND SRCS_DIR ${STATUS_DIR})
list(APPEND SRCS_DIR ${LOGGER_DIR})


add_library(robostdemo SHARED ${SRCS_DIR})

install(TARGETS robostdemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
