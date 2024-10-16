#include "vector.h"
#include "../error_handling.h"
#include "../exponents/exponents.h"
#include "../utilities/math_utils.h"
#include <stdlib.h>

/// @brief Initialize a n-dimensional vector
/// @param V vector
/// @param (int) dimension of the vector
/// @param vector_array the (double) array given by user
void initialize_vector(Vector *V, unsigned int vec_dimension, double *vector_array, int *error_code) {
    V->dimension = vec_dimension;
    V->vector = (double *)malloc(V->dimension * sizeof(double));
    if (V->vector == NULL) {
        *error_code = ERR_MEM_ALLOC;
    }
    for (int i = 0; i < V->dimension; i++) {
        V->vector[i] = vector_array[i];
    }
    double sum_part = 0;
    for (int i = 0; i < V->dimension; i++) {
        sum_part += square(V->vector[i]);
    }
    V->magnitude = power(sum_part, 0.5, error_code);
}

/// @brief Initialize a 2D vector
/// @param V vector
/// @param vector_array the (double) array given by user of size 2
void initialize_vector_2d(Vector *V, double vector_array[2], int *error_code) {
    initialize_vector(V, 2, vector_array, error_code);
}

/// @brief Initialize a 3D vector
/// @param V vector
/// @param vector_array the (double) array given by user of size 3
void initialize_vector_3d(Vector *V, double vector_array[3], int *error_code) {
    initialize_vector(V, 3, vector_array, error_code);
}

/// @brief Free the memory allocated to the vector
/// @param V vector
void free_vector(Vector *V) {
    free(V->vector);
    V->vector = NULL; // For dangling pointers
}

/// @brief Finds the Eucledian distance between two vectors
/// @param V1 vector
/// @param V2 vector
/// @return (double) distance
double distance(Vector V1, Vector V2, int *error_code) {
    // dist^2(x) = sigma(0, n) (x1i - x2i)^2

    // TODO: Fix This ugly logic
    int max_dimension = (V1.dimension > V2.dimension) ? V1.dimension : V2.dimension; // They may be of different dimension
    int flag = (V1.dimension > V2.dimension) ? (V2.dimension - 1) : -(V1.dimension - 1); // Negative flag if V2 has more components (-1 is since index start form 0)
    int dimension_diff = V1.dimension - V2.dimension;
    double difference_part = 0;
    double sum_part = 0;
    for (int i = 0; i < max_dimension; i++) {
        if ((dimension_diff !=0) && (absolute(flag) < i)) {
            // Fill with 0 if one vector is greater than than the other
            difference_part = (flag > 0) ? (V1.vector[i]) : (V2.vector[i]);
            sum_part += square(difference_part);
        } else {
            difference_part = (V1.vector[i]) - (V2.vector[i]);
            sum_part += square(difference_part);
        }
    }
    return power(sum_part, 0.5, error_code);
}

/// @brief Finds the dot product of the vectors
/// @param V1 vector
/// @param V2 vector
/// @return (double) dot product
double vector_dot_product(Vector V1, Vector V2) {
    int min_dimension = (V1.dimension > V2.dimension) ? V2.dimension : V1.dimension; // They may be of different dimension, just pic smaller one
    double product_part = 0;
    double sum_part = 0;
    for (int i = 0; i < min_dimension; i++) {
        product_part = (V1.vector[i]) * (V2.vector[i]);
        sum_part += product_part;
    }
    return sum_part;
}

void cross_product_3d(Vector V1, Vector V2, Vector *Vec_Result, int *error_code) {
    if ((V1.dimension == 3) || (V2.dimension == 3)) {
        double i_comp = (V1.vector[1] * V2.vector[2]) - (V1.vector[2] * V2.vector[1]);
        double j_comp = (V1.vector[0] * V2.vector[2]) - (V1.vector[2] * V2.vector[0]);
        double k_comp = (V1.vector[0] * V2.vector[1]) - (V1.vector[1] * V2.vector[0]);
        double temp_arr[3] = {i_comp, j_comp, k_comp};
        initialize_vector_3d(Vec_Result, temp_arr, error_code);
    } else {
        Vec_Result = NULL;
    }
}
