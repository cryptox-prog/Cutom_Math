#ifndef TRIGONOMETRIC_H
#define TRIGONOMETRIC_H

double sine(double angle, int is_rad);
double cosine(double angle, int is_rad);
double tangent(double angle, int is_rad, int *error_code);
double cosecant(double angle, int is_rad, int *error_code);
double secant(double angle, int is_rad, int *error_code);
double cotangent(double angle, int is_rad, int *error_code);

#endif // TRIGONOMETRIC_H
