#include <stdio.h>
#include <stdlib.h>

/*
gcc -I/path/to/customMath -c customMath/utilities/math_utils.c
gcc -I/path/to/customMath -c customMath/exponents/exponents.c
gcc -I/path/to/customMath -c customMath/trigonometery/trigonometric.c

gcc -o my_application math_utils.o exponents.o trigonometric.o -I/path/to/customMath

*/


int main(){
    double input_num_1, input_num_2;
    printf("Enter a number: ");
    scanf("%lf", &input_num_1);
    //printf("Raise it to the power: ");
    //scanf("%lf", &input_num_2);
    printf("Trial: %lf", sine(input_num_1));
    return 0;
}
