#include <gtest/gtest.h>
#include "../src/calculator.h"
#include <iostream>

class CalculatorTest : public testing::Test {
    protected:
    Calculator *calc;
    void SetUp() {
        calc = new Calculator;
        std::cout << "Calculator Started...";
    }
    void TearDown() {
        delete calc;
        std::cout << "Calculator Stopped...";
    }
};

TEST_F(CalculatorTest, add) {
    EXPECT_EQ(calc->add(4, 5), 9);
}

TEST_F(CalculatorTest, subtract) {
    EXPECT_EQ(calc->sub(4, 5), -1);
}

TEST_F(CalculatorTest, multiply) {
    EXPECT_EQ(calc->multiply(4, 5), 20);
}

TEST_F(CalculatorTest, divide) {
    EXPECT_EQ(calc->divide(15, 5), 3);
}
