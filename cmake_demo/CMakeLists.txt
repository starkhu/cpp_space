cmake_minimum_required(VERSION 2.8)


project(MathTest)

configure_file (

"${PROJECT_SOURCE_DIR}/config.h.in"

"${PROJECT_BINARY_DIR}/config.h"

)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/build)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
aux_source_directory(. DIR_SRCS)

add_subdirectory(math)

add_executable(MathDemo main.cc)

target_link_libraries(MathDemo MathFunction)

install(TARGETS MathDemo DESTINATION bin)




enable_testing()

add_test(test_run MathDemo)
set_tests_properties(test_run PROPERTIES PASS_REGULAR_EXPRESSION "3")


# Provides an option for the user to select as ON or OFF.
# If no initial <value> is provided, OFF is used
option(STRVAR "define var STRVAR" ON)
option(INTVAR "define var INTVAR" OFF)

if (DEFINED STRVAR)
  message("var STRVAR defined")
else()
  message("var STRVAR is not defined")
endif()


if (${STRVAR} STREQUAL "ON")
  message("STRVAR  equals to ON ")
else()
  message("STRVAR doesnot equals to ON " ${STRVAR})
endif()


