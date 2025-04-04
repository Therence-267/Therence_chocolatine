/*
** EPITECH PROJECT, 2025
** 10_trigo
** File description:
** math_function
*/

#ifndef TRIGO_H
    #define TRIGO_H
    #include "matrix.h"

Matrix* compute_exp(const Matrix *m, int terms);
Matrix* compute_cos(const Matrix *m, int terms);
Matrix* compute_sin(const Matrix *m, int terms);
Matrix* compute_cosh(const Matrix *m, int terms);
Matrix* compute_sinh(const Matrix *m, int terms);
#endif
