#include "unity/unity.h"
#include "exponential/exponen_test.h"

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

    RUN_TEST(test_exponentiation_function_of_zero);
    RUN_TEST(test_exponentiation_function_of_positive_small_value);
    RUN_TEST(test_exponentiation_function_of_positive_large_value);
    RUN_TEST(test_exponentiation_function_of_negative_value);
    RUN_TEST(test_exponentiation_function_of_negative_large_value);
    RUN_TEST(test_exponentiation_function_of_small_value);
    RUN_TEST(test_exponentiation_function_of_large_value);
    RUN_TEST(test_exponentiation_function_of_large_negative_value);

    return UNITY_END();
}
