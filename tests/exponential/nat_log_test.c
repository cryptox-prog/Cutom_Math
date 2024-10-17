#include "../unity/unity.h"
#include "exponen_test.h"
#include "../../src/lib/customMath/custom_math.h"

void test_natural_logarithm_of_1(void) {
    int error_code = 0;
    double result = natural_logarithm(1.0, &error_code);
    TEST_ASSERT_EQUAL_INT(0, error_code);  // No error expected
    TEST_ASSERT_EQUAL_DOUBLE(0.0, result);  // ln(1) = 0
}

void test_natural_logarithm_of_greater_than_1(void) {
    int error_code = 0;
    double result = natural_logarithm(2.71828, &error_code);  // ~e
    TEST_ASSERT_EQUAL_INT(0, error_code);  // No error expected
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // ln(e) ~ 1
}

void test_natural_logarithm_of_value_near_1(void) {
    int error_code = 0;
    double result = natural_logarithm(1.0001, &error_code);
    TEST_ASSERT_EQUAL_INT(0, error_code);  // No error expected
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0001, result);  // ln(1.0001) ~ 0.0001
}

void test_natural_logarithm_of_zero(void) {
    int error_code = 0;
    double result = natural_logarithm(0.0, &error_code);
    TEST_ASSERT_EQUAL_INT(POSITIVE_FUNC, error_code);  // Error code should indicate invalid input
    TEST_ASSERT_EQUAL_DOUBLE(0.0, result);  // Should return 0.0 in case of error
}

void test_natural_logarithm_of_negative_number(void) {
    int error_code = 0;
    double result = natural_logarithm(-5.0, &error_code);
    TEST_ASSERT_EQUAL_INT(POSITIVE_FUNC, error_code);  // Error code should indicate invalid input
    TEST_ASSERT_EQUAL_DOUBLE(0.0, result);  // Should return 0.0 in case of error
}

void test_natural_logarithm_of_large_number(void) {
    int error_code = 0;
    double result = natural_logarithm(100.0, &error_code);
    TEST_ASSERT_EQUAL_INT(0, error_code);  // No error expected
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 4.60517, result);  // ln(100) ~ 4.60517
}
