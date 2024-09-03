#include "exponents.h"
#include "../math_constants.h"
#include "../utilities/math_utils.h"
#include <stdlib.h>
#include <stdio.h>


double natural_logarithm(double num) {
    /*
     * Taylor Series Expansion of ln(1+x)
     * sigma(infinity, 1)  = [(-1)^(n+1)]*[(x^n)/n]
    */
    double buffer_logarithm_value = 0.0;

    if ((num >= 1) && (num < (1 + TOLERANCE))){
        // If number is very close to 1 just return 0.
        // ln(1) = 0
        return 0.0;
    }
    else if ((num) > 0) {
        while (num > 1) {
            // ln(x*y) = ln(x) + ln(y)
            buffer_logarithm_value += LN_SIMPLIFICATION_CONSTANT;
            num /= SIMPLIFICATION_CONSTANT;
        }
        double argument = num - 1;

        double term = argument;
        int i = 1;
        while ((i <= MAX_TERM_LIMIT) && (absolute(term)/i > TOLERANCE)) {
            buffer_logarithm_value += term/i;
            i++;
            term *= -argument;
        }
        return buffer_logarithm_value;
    } else {
        printf("The number should be greater than 0.");
        exit(EXIT_FAILURE);
    }
}

double exponentiation_function(double num) {
    /*
     * Taylor series expansion of e^x
     * sigma(infinity, 0) = x^n/n!
    */
    if (absolute(num) < APPROXIMATION_THRESHOLD) {
        return (1 + num + (num*num/2));
    }
    else {
        double buffer_e_x_value = 1.0;
        
        int num_steps = (int)(num / SIMPLIFICATION_CONSTANT);
        if (num_steps != 0) {
            num -= num_steps * SIMPLIFICATION_CONSTANT;

            double buffer_simplification_constant_powered = 1.0;
            double base = E_SIMPLIFICATION_CONSTANT;
            while (num_steps > 0) {
                if (num_steps % 2 == 1) {
                    buffer_simplification_constant_powered *= base;
                }
                base *= base;
                num_steps /= 2;
            }
            buffer_e_x_value = buffer_simplification_constant_powered;
        }

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

double power(double num, double exp) {
    if (num == 0) {
        return 0.0;
    } else if (num > 0) {
        return exponentiation_function(exp * natural_logarithm(num));
    } else {
        if (is_int(num) == 1) {
            if (is_even(num) == 1) {
                return exponentiation_function(exp * natural_logarithm(absolute(num)));
            } else {
                return -exponentiation_function(exp * natural_logarithm(absolute(num)));
            }
        } else {
            printf("Raising -1 to a non integer value is beyond the scope.");
            exit(EXIT_FAILURE);
        }
    }
}
