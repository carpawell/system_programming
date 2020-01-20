#include <gtest/gtest.h>
#include <myproject/6_task/Geometry.h>

TEST(GEOMETRY, CIRCLE_TRAIT) {
	float rad = 1;
    auto c = Circle<float>(rad);

    EXPECT_EQ(sizeof(rad), std::Trait<Circle<float>>::size(c));
}

TEST(GEOMETRY, RECTANGLE_TRAIT) {
	double width = 1;
	double height = 2;
    auto r = Rectangle<double>(width, height);

    EXPECT_EQ(sizeof(width) + sizeof(height), std::Trait<Rectangle<double>>::size(r));
}