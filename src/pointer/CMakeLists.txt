#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(BASIC_SRCS "")
aux_source_directory(. DIR_LIB_SRCS)
aux_source_directory(shared_ptr SHARED_PTR_DIR)
aux_source_directory(unique_ptr UNIQUE_PTR_DIR)
list(APPEND BASIC_SRCS ${DIR_LIB_SRCS})
list(APPEND BASIC_SRCS ${SHARED_PTR_DIR})
list(APPEND BASIC_SRCS ${UNIQUE_PTR_DIR})

add_library(pointerdemo SHARED ${BASIC_SRCS})

install(TARGETS pointerdemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
