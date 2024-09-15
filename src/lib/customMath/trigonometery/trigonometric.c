#include "trigonometric.h"
#include "../math_constants.h"
#include "../utilities/math_utils.h"
#include "../exponents/exponents.h"

/// @brief Calculates value of sine using taylor series
/// @param angle (double) intput angle
/// @param is_rad (int) 1 if in radian and 0 if degree
/// @return (double) sin(x)
double sine(double angle, int is_rad) {
    //Taylor Series Expansion of Sine Function
    //sigma(0, infinity) = {[(-1)^(n)]/[(2n + 1)!]}*[x^(2n + 1)]}
    angle = (is_rad == 0) ? deg_to_rad(angle) : angle;  // Convert to radians, if needed
    if (absolute(angle) < APPROXIMATION_THRESHOLD) {
        return angle;
    }
    else {
        if (absolute(angle) > PI / 2) {
            // sin(x % 2PI) = sin(x) 
            angle = mod(angle, 2*PI);
        }
        if (absolute(angle) > 2 * PI) {
            // sin(x - 2PI) = sin(x)
            int cycles = (int)(angle / (2*PI));
            double simplification_factor = cycles * 2 * PI;
            angle += (is_positive(angle) == 1) ? -simplification_factor : simplification_factor;
            angle = mod(angle, 2*PI);
        }
        double term = angle; // First term of the series
        double buffer_sine_value = term; // Intialize answer placeholder
        int i = 1;
        while (i < MAX_TERM_LIMIT && (term > TOLERANCE || term < -TOLERANCE)) {
            term *= -angle * angle / ((2 * i) * ((2 * i) + 1));
            buffer_sine_value += term;
            i++;
        }
    return buffer_sine_value;
    }
}

/// @brief Calculates value of cosine using sin(90 - x) = cos(x)
/// @param angle (double) intput angle
/// @param is_rad (int) 1 if in radian and 0 if degree
/// @return (double) cos(x)
double cosine(double angle, int is_rad) {
    double phase_change  = (is_rad == 1) ? PI/2 : STRAIGHT_ANGLE/2;
    return sine((phase_change - angle), is_rad);
}

/// @brief Calculates value of cosine using tan(x) = sin(x)/cos(x)
/// @param angle (double) intput angle
/// @param is_rad (int) 1 if in radian and 0 if degree
/// @return (double) tan(x)
double tangent(double angle, int is_rad) {
    return (sine(angle, is_rad) / cosine(angle, is_rad));
}

/// @brief Calculates value of cosine using cosec(x) = 1/sin(x)
/// @param angle (double) intput angle
/// @param is_rad (int) 1 if in radian and 0 if degree
/// @return (double) cosec(x)
double cosecant(double angle, int is_rad) {
    return (1/sine(angle, is_rad));
}

/// @brief Calculates value of cosine using sec(x) = 1/cos(x)
/// @param angle (double) intput angle
/// @param is_rad (int) 1 if in radian and 0 if degree
/// @return (double) sec(x)
double secant(double angle, int is_rad) {
    return (1/cosine(angle, is_rad));
}

/// @brief Calculates value of cosine using cot(x) = 1/tan(x)
/// @param angle (double) intput angle
/// @param is_rad (int) 1 if in radian and 0 if degree
/// @return (double) cot(x)
double cotangent(double angle, int is_rad) {
    return (1/tangent(angle, is_rad));
}
