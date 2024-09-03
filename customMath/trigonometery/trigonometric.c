#include "trigonometric.h"
#include "../math_constants.h"
#include "../utilities/math_utils.h"
#include "../exponents/exponents.h"

double sine(double angle, int is_rad) {
    /*
     * Taylor Series Expansion of Sine Function
     * sigma(infinity, 0) = {[(-1)^(n)]/[(2n + 1)!]}*[x^(2n + 1)]
    */
    angle = (is_rad != 1) ? rad_to_deg(angle) : angle;
    if (absolute(angle) < APPROXIMATION_THRESHOLD) {
        return angle;
    }
    else {
        //double rad_angle = (rad_angle > PI/2) ?: rad_angle/(2*PI) , rad_angle;
        double term, buffer_sine_value = 0.0;
    
        // Normalize x to the range [0, 2π)
        /*rad_angle = fmod(rad_angle, 2 * PI);
        if (rad_angle < 0) {
            rad_angle += 2 * PI;
        }*/
        
        int i = 0;
        do {
            term = power(angle, 2 * i + 1) / factorial(2 * i + 1);
            if (i % 2 == 1) {
                term = -term;
            }
            buffer_sine_value += term;
            i++;
        } while (i < MAX_TERM_LIMIT && absolute(term) >= TOLERANCE);
    return buffer_sine_value;
    }
}