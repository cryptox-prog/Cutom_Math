#include "../math_constants.h"
#include "math_utils.h"


double rad_to_deg(double rad_angle) {
    return rad_angle*(STRAIGHT_ANGLE/PI);
}

double deg_to_rad(double deg_angle) {
    return deg_angle*(PI/STRAIGHT_ANGLE);
}

double absolute(double num) {
    return (is_positive(num) * num);
}

int is_positive(double num) {
    /*
     * return 1 is true and -1 if false
    */
    return (num > 0) ? 1 : -1;
}

int is_int(double num) {
    num = absolute(num);
    return (((num - (int)num) < TOLERANCE)) ? 1 : 0;
}

int is_even(double num) {
    return (((int)absolute(num) % 2 < TOLERANCE) || num == 0) ? 1 : 0;
}

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
