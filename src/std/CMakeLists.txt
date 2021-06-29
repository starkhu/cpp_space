#add_compile_options(-std=c++11)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(BASIC_SRCS "")
aux_source_directory(key_word KEY_WORD_DIR)
aux_source_directory(std_function STD_FUNCTION_DIR)
list(APPEND BASIC_SRCS ${KEY_WORD_DIR})
list(APPEND BASIC_SRCS ${STD_FUNCTION_DIR})

message("************************")
message(${BASIC_SRCS})
message("************************")
add_library(stddemo SHARED ${BASIC_SRCS})

install(TARGETS stddemo DESTINATION ${CMAKE_SOURCE_DIR}/lib)
