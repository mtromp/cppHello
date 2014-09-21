cmake_minimum_required (VERSION 2.6)
project (CppHello)

ENABLE_TESTING()

# The version number.
set (HELLO_VERSION_MAJOR 1)
set (HELLO_VERSION_MINOR 0)

# Greetings
include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/Greetings"
  "${PROJECT_SOURCE_DIR}/GildedRose"
)
add_subdirectory(Greetings)
add_subdirectory(GildedRose)

configure_file (
  "${PROJECT_SOURCE_DIR}/HelloConfig.h.in"
  "${PROJECT_BINARY_DIR}/HelloConfig.h"
)

add_executable(Hello Hello.cpp)
target_link_libraries (Hello Greetings GildedRose)

