#include <gtest/gtest.h>
#include <myproject/MyCat.h>
#include <array>

TEST(cat, test1array){
    std::array<float, 3> vec1{1.0f, 2.0f, 3.0f};

    std::array<float, 3> r = cat(vec1);  

    EXPECT_EQ(r[0], 1.0f); 
    EXPECT_EQ(r[1], 2.0f);
    EXPECT_EQ(r[2], 3.0f);  
}

TEST(cat, test2arrays){
    std::array<int, 3> vec1{1, 2, 3};
    std::array<int, 3> vec2{4, 5, 6};

    std::array<int, 6> r = cat(vec1, vec2);  

    EXPECT_EQ(r[0], 1); 
    EXPECT_EQ(r[1], 2);
    EXPECT_EQ(r[2], 3);
    EXPECT_EQ(r[3], 4);
    EXPECT_EQ(r[4], 5);
    EXPECT_EQ(r[5], 6);    
}

TEST(cat, test3arrays){
    std::array<float, 3> vec1{1.0f, 2.0f, 3.0f};
    std::array<float, 2> vec2{4.0f, 5.0f};
    std::array<float, 3> vec3{6.0f, 7.0f, 8.0f};

    std::array<float, 8> r = cat(vec1, vec2, vec3);  

    EXPECT_EQ(r[0], 1.0f); 
    EXPECT_EQ(r[1], 2.0f);
    EXPECT_EQ(r[2], 3.0f);
    EXPECT_EQ(r[3], 4.0f);
    EXPECT_EQ(r[4], 5.0f); 
    EXPECT_EQ(r[5], 6.0f); 
    EXPECT_EQ(r[6], 7.0f); 
    EXPECT_EQ(r[7], 8.0f);   
}
