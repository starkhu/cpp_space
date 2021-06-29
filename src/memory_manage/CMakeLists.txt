#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

aux_source_directory(. MEMORY_MANAGE_DIR)

#add_library(Anonymous SHARED ${DIR_LIB_SRCS})
message("************************")
message(${MEMORY_MANAGE_DIR})
message("************************")
add_library(memorydemo SHARED ${MEMORY_MANAGE_DIR})

install(TARGETS memorydemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
