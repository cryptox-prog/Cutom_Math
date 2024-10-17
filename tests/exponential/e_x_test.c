#include "../unity/unity.h"
#include "exponen_test.h"
#include "../../src/lib/customMath/custom_math.h"

#define TOLERENCE_RED 1e-11

void test_exponentiation_function_of_zero(void) {
    double result = exponentiation_function(0.0);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 1.0, result);  // e^0 = 1
}

void test_exponentiation_function_of_positive_small_value(void) {
    double result = exponentiation_function(0.1);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 1.10517091808, result);  // e^0.1 ~ 1.10517091808
}

void test_exponentiation_function_of_positive_large_value(void) {
    double result = exponentiation_function(5.0);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 148.413159103, result);  // e^5 ~ 148.413159103
}

void test_exponentiation_function_of_negative_value(void) {
    double result = exponentiation_function(-1.0);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 0.36787944117, result);  // e^-1 ~ 0.36787944117
}

void test_exponentiation_function_of_negative_large_value(void) {
    double result = exponentiation_function(-5.0);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 0.00673794699, result);  // e^-5 ~ 0.00673794699
}

void test_exponentiation_function_of_small_value(void) {
    double result = exponentiation_function(0.0001);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 1.000100005, result);  // e^0.0001 ~ 1.000100005
}

void test_exponentiation_function_of_large_value(void) {
    double result = exponentiation_function(10.0);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 22026.4657948, result);  // e^10 ~ 22026.4657948
}

void test_exponentiation_function_of_large_negative_value(void) {
    double result = exponentiation_function(-10.0);
    TEST_ASSERT_DOUBLE_WITHIN(TOLERENCE_RED, 0.00004539992, result);  // e^-10 ~ 0.00004539992
}
