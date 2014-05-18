cmake_minimum_required (VERSION 2.6)
project (CppHello)


# Where Google Test's .h files can be found.
set(gtest_DIR "/Users/rj/gtest-1.7.0")
include_directories(
  ${gtest_DIR}/include
  ${gtest_DIR})


configure_file (
  "${PROJECT_SOURCE_DIR}/HelloConfig.h.in"
  "${PROJECT_BINARY_DIR}/HelloConfig.h"
)
 

add_executable(Hello Hello.cpp)
