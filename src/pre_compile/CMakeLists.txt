#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

aux_source_directory(. DIR_LIB_SRCS)

add_library(pre_compile SHARED ${DIR_LIB_SRCS})

install(TARGETS pre_compile DESTINATION ${CMAKE_SOURCE_DIR}/lib)
