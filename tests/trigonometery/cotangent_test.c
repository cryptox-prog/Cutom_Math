#include "../unity/unity.h"
#include "trig_test.h"
#include "../../src/lib/customMath/custom_math.h"

// Test for cotangent(π/4) in radians
void test_cotangent_of_pi_over_4_radians(void) {
    int error_code = 0;
    double result = cotangent(PI / 4, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(0, error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // Expected result: 1
}

// Test for cotangent(π) in radians
void test_cotangent_of_pi_radians(void) {
    int error_code = 0;
    double result = cotangent(PI, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(DIV_BY_ZERO, error_code);  // Expected division by zero error
}

// Test for cotangent(3π/4) in radians
void test_cotangent_of_3_pi_over_4_radians(void) {
    int error_code = 0;
    double result = cotangent(3 * PI / 4, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(0, error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, -1.0, result);  // Expected result: -1
}
