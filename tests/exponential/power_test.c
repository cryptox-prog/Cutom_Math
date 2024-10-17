#include "../unity/unity.h"
#include "exponen_test.h"
#include "../../src/lib/customMath/custom_math.h"

void test_power_of_zero_base(void) {
    int error_code = 0;
    double result = power(0.0, 2.0, &error_code);
    TEST_ASSERT_EQUAL(0.0, result);  // 0^2 = 0
    TEST_ASSERT_EQUAL(0, error_code);
}

void test_power_of_positive_base_with_positive_exponent(void) {
    int error_code = 0;
    double result = power(2.0, 3.0, &error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 8.0, result);  // 2^3 = 8
    TEST_ASSERT_EQUAL(0, error_code);
}

void test_power_of_positive_base_with_negative_exponent(void) {
    int error_code = 0;
    double result = power(2.0, -2.0, &error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.25, result);  // 2^-2 = 0.25
    TEST_ASSERT_EQUAL(0, error_code);
}

void test_power_of_negative_base_with_even_integer_exponent(void) {
    int error_code = 0;
    double result = power(-2.0, 2.0, &error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 4.0, result);  // (-2)^2 = 4
    TEST_ASSERT_EQUAL(0, error_code);
}

void test_power_of_negative_base_with_odd_integer_exponent(void) {
    int error_code = 0;
    double result = power(-2.0, 3.0, &error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, -8.0, result);  // (-2)^3 = -8
    TEST_ASSERT_EQUAL(0, error_code);
}

void test_power_of_negative_base_with_fractional_exponent(void) {
    int error_code = 0;
    double result = power(-2.0, 0.5, &error_code);
    TEST_ASSERT_EQUAL(0.0, result);  // Complex result, should trigger error
    TEST_ASSERT_EQUAL(COMPLEX_RES, error_code);  // Complex result error
}

void test_power_of_fractional_base_with_positive_exponent(void) {
    int error_code = 0;
    double result = power(0.5, 2.0, &error_code);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.25, result);  // (0.5)^2 = 0.25
    TEST_ASSERT_EQUAL(0, error_code);
}
