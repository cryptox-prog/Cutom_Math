#include "../unity/unity.h"
#include "trig_test.h"
#include "../../src/lib/customMath/custom_math.h"

// Test for sine(0) in radians
void test_sine_of_zero_radians(void) {
    double result = sine(0, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0, result);  // Expected result: 0
}

// Test for sine(π/2) in radians
void test_sine_of_pi_over_2_radians(void) {
    double result = sine(PI / 2, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // Expected result: 1
}

// Test for sine(π) in radians
void test_sine_of_pi_radians(void) {
    double result = sine(PI, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0, result);  // Expected result: 0
}

// Test for sine(3π/2) in radians
void test_sine_of_3_pi_over_2_radians(void) {
    double result = sine(3 * PI / 2, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, -1.0, result);  // Expected result: -1
}

// Test for sine(2π) in radians
void test_sine_of_2_pi_radians(void) {
    double result = sine(2 * PI, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0, result);  // Expected result: 0
}

// Test for sine(90°) in degrees
void test_sine_of_90_degrees(void) {
    double result = sine(90, 0);  // 0 indicates degrees
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 1.0, result);  // Expected result: 1
}

// Test for sine(180°) in degrees
void test_sine_of_180_degrees(void) {
    double result = sine(180, 0);  // 0 indicates degrees
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0, result);  // Expected result: 0
}

// Test for sine with a small angle approximation
void test_sine_small_angle_approximation(void) {
    double small_angle = 0.001;
    double result = sine(small_angle, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, small_angle, result);  // Expected result: small_angle
}

// Test for sine with a large angle beyond 2π
void test_sine_large_angle(void) {
    double large_angle = 10 * PI;  // This is a large angle
    double result = sine(large_angle, 1);  // 1 indicates radians
    TEST_ASSERT_DOUBLE_WITHIN(TOLERANCE, 0.0, result);  // Expected result: sine cycles, so it should be ~0
}