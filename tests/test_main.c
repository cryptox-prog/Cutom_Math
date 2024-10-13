#include "unity/unity.h"
#include "trigonometery/sine_test.h"

// Test setup and teardown functions (optional)
void setUp(void) {
    // Set up code if necessary
}

void tearDown(void) {
    // Clean up code if necessary
}

// Main function to run the tests
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sine_of_zero_radians);
    RUN_TEST(test_sine_of_pi_over_2_radians);
    RUN_TEST(test_sine_of_pi_radians);
    RUN_TEST(test_sine_of_3_pi_over_2_radians);
    RUN_TEST(test_sine_of_2_pi_radians);
    RUN_TEST(test_sine_of_90_degrees);
    RUN_TEST(test_sine_of_180_degrees);
    RUN_TEST(test_sine_small_angle_approximation);
    RUN_TEST(test_sine_large_angle);

    return UNITY_END();
}
