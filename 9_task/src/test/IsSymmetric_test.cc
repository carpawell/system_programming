#include <gtest/gtest.h>
#include "myproject/4_task/matrix.h"

using namespace std;

struct is_symm_param {
    Matrix<int> input;
    bool expected_output;
};

class is_symm_test: public ::testing::TestWithParam<is_symm_param> {};


TEST_P(is_symm_test, _) {
    const is_symm_param& param = GetParam();
    Matrix<int> matrix{param.input};
    bool answer = matrix.is_symmetric(1e-3);
    EXPECT_EQ(param.expected_output, answer);
}

INSTANTIATE_TEST_CASE_P(
        _,
        is_symm_test,
        ::testing::Values(
                is_symm_param {
                        {{1, 2}, {1, 2}}, false
                },
                is_symm_param {
                        {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}}, true
                },
                is_symm_param {
                        {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, true
                },
                is_symm_param {
                        {1}, true
                }

        )
);