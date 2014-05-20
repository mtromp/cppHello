add_library(Greetings Greetings.cpp)
add_executable(GreetingsTest GreetingsTest.cpp)
TARGET_LINK_LIBRARIES(GreetingsTest Greetings gtest pthread)
add_test(GreetingsTest GreetingsTest)

