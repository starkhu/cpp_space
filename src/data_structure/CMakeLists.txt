#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(BASIC_SRCS "")
aux_source_directory(array ARRAY_DIR)
aux_source_directory(char_star CHAR_STAR_DIR)
aux_source_directory(link_list LINK_LIST_DIR)
aux_source_directory(sstream SSTREAM_DIR)
aux_source_directory(stl STL_DIR)

aux_source_directory(string STRING_DIR)

list(APPEND BASIC_SRCS ${ARRAY_DIR})
list(APPEND BASIC_SRCS ${CHAR_STAR_DIR})
list(APPEND BASIC_SRCS ${LINK_LIST_DIR})
list(APPEND BASIC_SRCS ${SSTREAM_DIR})
list(APPEND BASIC_SRCS ${STL_DIR})
list(APPEND BASIC_SRCS ${STRING_DIR})

add_library(datastructure SHARED ${BASIC_SRCS})

install(TARGETS datastructure DESTINATION ${CMAKE_SOURCE_DIR}/lib)
