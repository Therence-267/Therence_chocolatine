/*
** EPITECH PROJECT, 2025
** 108_trigo
** File description:
** function math
*/

#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double **data;
    int size;
} Matrix;

void print_matrix(const Matrix *m);
Matrix* create_matrix(int size);
void free_matrix(Matrix *m);
Matrix* matrix_identity(int size);
Matrix* matrix_power(const Matrix *m, int power);
Matrix* matrix_scale(const Matrix *m, double scalar);
Matrix* matrix_add(const Matrix *a, const Matrix *b);

#endif
