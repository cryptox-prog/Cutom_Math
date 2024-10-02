#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    unsigned int dimension;
    double *vector;
    double magnitude;
} Vector;

void initialize_vector(Vector *V, unsigned int vec_dimension, double *vector_array);
void free_vector(Vector *V);
double distance(Vector V1, Vector V2);
double vector_dot_product(Vector V1, Vector V2);
void cross_product_3d(Vector V1, Vector V2, Vector *Vec_Result);

void initialize_vector_2d(Vector *V, double vector_array[2]);
void initialize_vector_3d(Vector *V, double vector_array[3]);

#endif
