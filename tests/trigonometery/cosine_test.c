#include "../unity/unity.h"
#include "trig_test.h"
#include "../../src/lib/customMath/custom_math.h"

// Test for cosine(0) in radians
void test_cosine_of_zero_radians(void) {
    double result = cosine(0, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // Expected result: 1
}

// Test for cosine(π/2) in radians
void test_cosine_of_pi_over_2_radians(void) {
    double result = cosine(PI / 2, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0, result);  // Expected result: 0
}

// Test for cosine(π) in radians
void test_cosine_of_pi_radians(void) {
    double result = cosine(PI, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, -1.0, result);  // Expected result: -1
}

// Test for cosine(2π) in radians
void test_cosine_of_2_pi_radians(void) {
    double result = cosine(2 * PI, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // Expected result: 1
}
