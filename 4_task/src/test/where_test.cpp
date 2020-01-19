#include <gtest/gtest.h>
#include "myproject/matrix.h"

using namespace std;


struct where_param {
    Matrix<int> input1;
    Matrix<int> input2;
    Matrix<int> expected_output;
};


class where_test: public ::testing::TestWithParam<where_param> {};

TEST_P(where_test, _) {
    const where_param& param = GetParam();
    Matrix<int> a{param.input1}, b{param.input2};
    Matrix<int> c = where(a < b, a, b);
    EXPECT_EQ(param.expected_output, c);
}

INSTANTIATE_TEST_CASE_P(
    _,
    where_test,
    ::testing::Values(
    where_param {
        {{1, 2}, {3, 4}},
        {{2, 1}, {4, 3}},
        {{1, 1}, {3, 3}}
    },
    where_param {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 2, 1}
    },
    where_param {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 9, 8}, {7, 6, 5}, {4, 3, 2}},
        {{1, 2, 3}, {4, 5, 5}, {4, 3, 2}}
    }

    )
);
