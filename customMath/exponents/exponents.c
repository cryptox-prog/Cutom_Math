#include "exponents.h"
#include "../math_constants.h"
#include "../utilities/math_utils.h"
#include <stdlib.h>
#include <stdio.h>

/// @brief Calculates natural logarithm using taylor series
/// @param num (double) the argument for the natural logarithm
/// @return (double) ln(x)
double natural_logarithm(double num) {
     // Taylor Series Expansion of ln(1+x)
     // sigma(0, infinity)  = [(-1)^(n+1)]*[(x^n)/n]
    double buffer_logarithm_value = 0.0;

    if ((num >= 1) && (num < (1 + TOLERANCE))){
        // If number is very close to 1 just return 0.
        // ln(1) = 0
        return 0.0;
    }
    else if ((num) > 0) {
        while (num > 1) {
            // ln(x*y) = ln(x) + ln(y)
            // Use this property with pre calculated values to bring x closer to 1 and increase accuracy
            buffer_logarithm_value += LN_SIMPLIFICATION_CONSTANT;
            num /= SIMPLIFICATION_CONSTANT;
        }
        double argument = num - 1;

        // Apply Taylor Expansion
        double term = argument;
        int i = 1;
        while ((i <= MAX_TERM_LIMIT) && (absolute(term)/i > TOLERANCE)) {
            buffer_logarithm_value += term/i;
            i++;
            term *= -argument;
        }
        return buffer_logarithm_value;
    } else {
        // ln(0) -> Undefined
        printf("The number should be greater than 0.");
        exit(EXIT_FAILURE);
    }
}

/// @brief Calculates exponential function using taylor series
/// @param num (double) the power to which e will be raised
/// @return (double) e^x
double exponentiation_function(double num) {
     // Taylor series expansion of e^x
     // sigma(0, infinity) = x^n/n!
    if (absolute(num) < APPROXIMATION_THRESHOLD) {
        // Use approximation for very small values
        // e^x = 1 + x + (x^2)/2
        return (1 + num + ((num*num)/2));
    }
    else {
        double buffer_e_x_value = 1.0;
        
        // e^(x+y) = (e^x)*(e^y)
        // Use this property with pre calculated values to bring x closer to 1 and increase accuracy

        // Find the number of times Simplification constant needs to subtracted
        int num_steps = (int)(num / SIMPLIFICATION_CONSTANT);
        if (num_steps != 0) {
            num -= num_steps * SIMPLIFICATION_CONSTANT;

            double buffer_simplification_constant_powered = 1.0;
            double base = E_SIMPLIFICATION_CONSTANT;

            // Raise the pre-calculated constant to the number times it was subtracted
            // Use Exponentiation by Squaring
            while (num_steps > 0) {
                // at even power the base is just multiplied by itself and the power is halved
                // at odd power base is multiplies to answer variable then sqaured and halving takes place
                if (is_even(num_steps) == 0) {
                    buffer_simplification_constant_powered *= base;
                }
                base *= base;  // Square the base
                num_steps /= 2;  // Integer Division
            }
            buffer_e_x_value = buffer_simplification_constant_powered;
        }


        // Apply Taylor Expansion
        int i = 1;
        double x_term = num;
        double term = 1.0;
        double buffer_e_x_value_taylor = 1.0;
        while ((i <= MAX_TERM_LIMIT) && (absolute(term) > TOLERANCE)) {
            term *= x_term/i;
            buffer_e_x_value_taylor += term;
            i++;
        }
        return (buffer_e_x_value * buffer_e_x_value_taylor);
    }
}

/// @brief Performs {a} raised to {x} using e^x and ln(x)
/// @param num (double) base
/// @param exp (double) exponent
/// @return (double) a^x
double power(double num, double exp) {
    // a^x = e^(x*ln(a))
    if (num == 0) {
        // 0^x = 0
        return 0.0;
    } else if (num > 0) {
        // No need to account for the domain of ln for positive base
        return exponentiation_function(exp * natural_logarithm(num));
    } else {
        if (is_int(num) == 1) {
            // can only handle integer values for negative bases
            if (is_even(num) == 1) {
                // (-1)^(2x) = 1
                return exponentiation_function(exp * natural_logarithm(absolute(num)));
            } else {
                // (-1)^(2x + 1) = -1
                return -exponentiation_function(exp * natural_logarithm(absolute(num)));
            }
        } else {
            // A fractional power of -1 can be complex
            printf("Raising -1 to a non integer value is beyond the scope.");
            exit(EXIT_FAILURE);
        }
    }
}
