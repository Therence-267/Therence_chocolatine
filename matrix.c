/*
** EPITECH PROJECT, 2025
** 108_trigo
** File description:
** function
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "matrix.h"

Matrix* create_matrix(int size) {
    Matrix *m = malloc(sizeof(Matrix));
    m->size = size;
    m->data = malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        m->data[i] = calloc(size, sizeof(double));
    }
    return m;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->size; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void print_matrix(const Matrix *m) {
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            printf("%.2f", m->data[i][j]);
            if (j < m->size - 1) printf("\t");
        }
        printf("\n");
    }
}

Matrix* matrix_identity(int size) {
    Matrix *id = create_matrix(size);
    for (int i = 0; i < size; i++) {
        id->data[i][i] = 1.0;
    }
    return id;
}

Matrix* matrix_power(const Matrix *m, int power) {
    if (power == 0) return matrix_identity(m->size);
    
    Matrix *result = create_matrix(m->size);
    Matrix *temp = create_matrix(m->size);
    
    // Copier la matrice originale
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            temp->data[i][j] = m->data[i][j];
        }
    }
    
    for (int p = 1; p < power; p++) {
        Matrix *product = create_matrix(m->size);
        for (int i = 0; i < m->size; i++) {
            for (int j = 0; j < m->size; j++) {
                for (int k = 0; k < m->size; k++) {
                    product->data[i][j] += temp->data[i][k] * m->data[k][j];
                }
            }
        }
        free_matrix(temp);
        temp = product;
    }
    
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            result->data[i][j] = temp->data[i][j];
        }
    }
    free_matrix(temp);
    return result;
}

Matrix* matrix_add(const Matrix *a, const Matrix *b) {
    Matrix *result = create_matrix(a->size);
    for (int i = 0; i < a->size; i++) {
        for (int j = 0; j < a->size; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

Matrix* matrix_scale(const Matrix *m, double scalar) {
    Matrix *result = create_matrix(m->size);
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            result->data[i][j] = m->data[i][j] * scalar;
        }
    }
    return result;
}
