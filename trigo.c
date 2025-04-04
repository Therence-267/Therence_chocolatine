/*
** EPITECH PROJECT, 2025
** trigo
** File description:
** function
*/

#include <math.h>
#include "trigo.h"
#include "matrix.h"
static double factorial(int n)
{
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

Matrix* compute_exp(const Matrix *m, int terms)
{
    Matrix *result = matrix_identity(m->size);
    Matrix *term = matrix_identity(m->size);    
    for (int k = 1; k < terms; k++) {
        Matrix *power = matrix_power(m, k);
        Matrix *scaled = matrix_scale(power, 1.0/factorial(k));
        Matrix *new_result = matrix_add(result, scaled);
        
        free_matrix(result);
        free_matrix(power);
        free_matrix(scaled);
        
        result = new_result;
    }
    return result;
}

Matrix* compute_cos(const Matrix *m, int terms)
{
    Matrix *result = matrix_identity(m->size);
    for (int k = 1; k < terms; k++) {
        double coeff = (k % 2 == 0) ? 1.0/factorial(2*k) : -1.0/factorial(2*k);
        Matrix *term = matrix_power(m, 2*k);
        Matrix *scaled = matrix_scale(term, coeff);
        Matrix *new_result = matrix_add(result, scaled);
        
        free_matrix(term);
        free_matrix(scaled);
        free_matrix(result);       
        result = new_result;
    }
    return result;
}
