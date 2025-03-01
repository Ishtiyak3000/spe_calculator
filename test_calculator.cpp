#include "calculator.h"
#include <gtest/gtest.h>
TEST(CalculatorTests, SquareRoot) {
    EXPECT_DOUBLE_EQ(squareRoot(16), 4);
}

TEST(CalculatorTests, Factorial) {
    EXPECT_EQ(factorial(5), 120);
}

TEST(CalculatorTests, NaturalLog) {
    EXPECT_DOUBLE_EQ(naturalLog(exp(1)), 1);
}

TEST(CalculatorTests, PowerFunction) {
    EXPECT_DOUBLE_EQ(power(2, 3), 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
