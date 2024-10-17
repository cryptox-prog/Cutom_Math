#include "../unity/unity.h"
#include "trig_test.h"
#include "../../src/lib/customMath/custom_math.h"

// Test for tangent(0) in radians
void test_tangent_of_zero_radians(void) {
    int error_code = 0;
    double result = tangent(0, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(0, error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0, result);  // Expected result: 0
}

// Test for tangent(π/4) in radians
void test_tangent_of_pi_over_4_radians(void) {
    int error_code = 0;
    double result = tangent(PI / 4, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(0, error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // Expected result: 1
}

// Test for tangent(π/2) in radians
void test_tangent_of_pi_over_2_radians(void) {
    int error_code = 0;
    double result = tangent(PI / 2, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(DIV_BY_ZERO, error_code);  // Expected division by zero error
}

// Test for tangent(3π/2) in radians
void test_tangent_of_3_pi_over_2_radians(void) {
    int error_code = 0;
    double result = tangent(3 * PI / 2, 1, &error_code);  // 1 indicates radians
    TEST_ASSERT_EQUAL(DIV_BY_ZERO, error_code);  // Expected division by zero error
}
