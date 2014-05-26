#include <gtest/gtest.h>
#include "Greetings.h"

TEST(GreetingsTest, WhenHelloIsCalledThenExpectHelloWorldString)
{
    Greetings* greetings = new Greetings();
    EXPECT_EQ("Hello, world!", greetings->hello());
    delete greetings;
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

