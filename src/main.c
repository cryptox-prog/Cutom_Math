#include <stdio.h>
#include <stdlib.h>
#include "lib/customMath/custom_math.h"

int main(){
    double input_num_1, input_num_2;
    printf("Enter a number: ");
    scanf("%lf", &input_num_1);
    //printf("Raise it to the power: ");
    //scanf("%lf", &input_num_2);
    printf("Trial: %lf", absolute(input_num_1));
    return 0;
}
