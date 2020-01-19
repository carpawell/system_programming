#include <gtest/gtest.h>
#include <myproject/MyTie.h>
#include <array>

TEST(MyTie, test2arrays){
    std::array<int, 6> r{1, 2, 3, 4, 5, 6};
    std::array<int, 3> vec1, vec2;

    tie(vec1, vec2) = r;

    EXPECT_EQ(vec1[0], 1);
    EXPECT_EQ(vec1[1], 2);
    EXPECT_EQ(vec1[2], 3);
    EXPECT_EQ(vec2[0], 4);
    EXPECT_EQ(vec2[1], 5);
    EXPECT_EQ(vec2[2], 6);
}

TEST(MyTie, test3arrays){
    std::array<int, 6> r{1, 2, 3, 4, 5, 6};
    std::array<int, 2> vec1, vec2, vec3;

    tie(vec1, vec2, vec3) = r;

    EXPECT_EQ(vec1[0], 1);
    EXPECT_EQ(vec1[1], 2);
    EXPECT_EQ(vec2[0], 3);
    EXPECT_EQ(vec2[1], 4);
    EXPECT_EQ(vec3[0], 5);
    EXPECT_EQ(vec3[1], 6);
}