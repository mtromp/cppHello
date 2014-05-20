cmake_minimum_required (VERSION 2.6)
project (CppHello)

ENABLE_TESTING()

# The version number.
set (HELLO_VERSION_MAJOR 1)
set (HELLO_VERSION_MINOR 0)

# Where Google Test's .h files can be found.
#set(gtest_DIR "/Users/rj/gtest-1.7.0")
#include_directories(
#  ${gtest_DIR}/include
#  ${gtest_DIR})

# Greetings
include_directories(
  "${PROJECT_SOURCE_DIR}/Greetings"
)
add_subdirectory(Greetings)

configure_file (
  "${PROJECT_SOURCE_DIR}/HelloConfig.h.in"
  "${PROJECT_BINARY_DIR}/HelloConfig.h"
)

add_executable(Hello Hello.cpp)
target_link_libraries (Hello Greetings)

