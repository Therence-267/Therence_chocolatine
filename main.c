/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "trigo.h"
#include <math.h>

void print_usage(void)
{
    printf("USAGE\n");
    printf("./108trigo fun a0 a1 a2 ...\n\n");
    printf("DESCRIPTION\n");
    printf("fun\tfunction to be applied, among \"EXP\", \"COS\", \"SIN\", \"COSH\", \"SINH\"\n");
    printf("ai\tcoefficients of the matrix\n");
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_usage();
    }    
    if (argc < 3) {
        return 84;
    } 
    const char *func = argv[1];
    int matrix_size = sqrt(argc - 2);
    if (matrix_size * matrix_size != argc - 2) {
        return 84;
    }
    Matrix *m = create_matrix(matrix_size);
    int arg_index = 2;
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            m->data[i][j] = atof(argv[arg_index++]);
        }
    }
    Matrix *result = NULL;
    if (strcmp(func, "EXP") == 0) {
        result = compute_exp(m, 100);
    } else if (strcmp(func, "COS") == 0) {
        result = compute_cos(m, 100);
    }
    if (result == NULL) {
        free_matrix(m);
        return 84;
    }
    print_matrix(result);
    free_matrix(m);
    free_matrix(result);
    return 0;
}
