#include <gtest/gtest.h>
#include <vector>
#include <myproject/TurnVector.h>

TEST(TURN90, WORNG_VECTOR_SIZE){
    std::vector<int> vec = {1,2,3};
    EXPECT_FALSE(turn_vector(vec, 90));
}

TEST(TURN90, WRONG_COUNT_OF_DEGREE){
    std::vector<int> vec = {1,2};
    EXPECT_FALSE(turn_vector(vec, 100));
}

TEST(TURN90, CLOCKWISE_TURN){
    std::vector<int> vec = {1,2};
    turn_vector(vec, 90);
    EXPECT_EQ(2, vec[0]);
    EXPECT_EQ(-1, vec[1]);
}

TEST(TURN90, COUNTERCLOCK-WISE_TURN){
    std::vector<int> vec = {1,2};
    turn_vector(vec, -90);
    EXPECT_EQ(-2, vec[0]);
    EXPECT_EQ(1, vec[1]);
}