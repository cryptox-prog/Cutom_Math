#include "../math_constants.h"
#include "math_utils.h"

/// @brief Converts radian angle to degree angle
/// @param rad_angle (double) radian input
/// @return (double) degree ouput
double rad_to_deg(double rad_angle) {
    return rad_angle*(STRAIGHT_ANGLE/PI);
}

/// @brief Converts degree angle to radian angle
/// @param deg_angle (double) degree input
/// @return (double) radian output
double deg_to_rad(double deg_angle) {
    return deg_angle*(PI/STRAIGHT_ANGLE);
}

/// @brief Converts negative numbers to positive
/// @param num (double) input number
/// @return (double) |x|
double absolute(double num) {
    return (is_positive(num) * num);
}

/// @brief Determines if input is a positive number
/// @param num (double) input number
/// @return 1 if positive input and -1 if negative input
int is_positive(double num) {
    /*
     * return 1 is true and -1 if false
    */
    return (num > 0) ? 1 : -1;
}

/// @brief Determine if a number in double for is a int
/// @param num (double) input number
/// @return 1 if input is integer and 0 if input is not integer
int is_int(double num) {
    num = absolute(num);
    return (((num - (int)num) < TOLERANCE)) ? 1 : 0;
}

/// @brief Check if input number is even
/// @param num (double) input number
/// @return 1 if even and 0 if odd
int is_even(double num) {
    return (((int)absolute(num) % 2 < TOLERANCE) || num == 0) ? 1 : 0;
}

/// @brief Find the factorial using loop
/// @param num (double) input number
/// @return (int) x!
unsigned long long factorial(int num) {
    unsigned long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}
