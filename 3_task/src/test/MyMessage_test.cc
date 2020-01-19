#include <gtest/gtest.h>
#include <myproject/MyMessage.h>
#include <iostream>
#include <string>

TEST(MyMessage, WrongNumOfArgs){
    EXPECT_FALSE(message(std::cout, "% + % = %", "test_string", 5));
    EXPECT_FALSE(message(std::cout, "% + % = %", 1));
    EXPECT_FALSE(message(std::cout, "% + % = %", "test_string", 10, 20, 30.0));
}

TEST(MyMessage, String){
    std::stringstream strings_outstream;

    message(strings_outstream, "% + % = %", "a", 1, 3.0);

    std::string str1 = strings_outstream.str();
    std::string str2 = "a + 1 = 3";
    EXPECT_EQ(str1, str2);
}