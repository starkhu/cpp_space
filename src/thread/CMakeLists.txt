#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

aux_source_directory(. DIR_LIB_SRCS)

add_library(threaddemo SHARED ${DIR_LIB_SRCS})

install(TARGETS threaddemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
