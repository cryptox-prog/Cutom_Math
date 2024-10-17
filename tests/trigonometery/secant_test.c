#include "../unity/unity.h"
#include "trig_test.h"
#include "../../src/lib/customMath/custom_math.h"

// Test for secant(0) in radians
void test_secant_of_zero_radians(void) {
    int error_code = 0;
    double result = secant(0, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(0, error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // Expected result: 1
}

// Test for secant(π/2) in radians
void test_secant_of_pi_over_2_radians(void) {
    int error_code = 0;
    double result = secant(PI / 2, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(DIV_BY_ZERO, error_code);  // Expected division by zero error
}

// Test for secant(π) in radians
void test_secant_of_pi_radians(void) {
    int error_code = 0;
    double result = secant(PI, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(0, error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, -1.0, result);  // Expected result: -1
}
