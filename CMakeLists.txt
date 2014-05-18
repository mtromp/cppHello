cmake_minimum_required (VERSION 2.6)
project (CppHello)

configure_file (
  "${PROJECT_SOURCE_DIR}/HelloConfig.h.in"
  "${PROJECT_BINARY_DIR}/HelloConfig.h"
)
 

add_executable(Hello Hello.cpp)
