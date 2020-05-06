/**
 * Matrix multiplication
 * Using dynamic memory allocation - CS102.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

int main() {
    int R, C; scanf("%d%d", &R, &C);

    // Initalise two 2-d matrix, using dynamic memory allocation.
    double** first_matrix  = (double**)malloc(R);
    double** second_matrix = (double**)malloc(C);

    // Get the first matrix
    for (int i = 0; i < R; ++i) {
        first_matrix[i] = (double*)malloc(sizeof(R) * C);
        for (int j = 0; j < C; ++j) scanf("%lf", &first_matrix[i][j]);
    }

    // Get the second Matrix
    for (int i = 0; i < C; ++i) {
        second_matrix[i] = (double*)malloc(sizeof(C) * R);
        for (int j = 0; j < R; ++j) scanf("%lf", &second_matrix[i][j]);
    }


    // Release the first Matrix
    for (int i = 0; i < R; ++i) free(first_matrix[i]);
    free(first_matrix);

    // Release the second Matrix
    for (int i = 0; i < C; ++i) free(second_matrix[i]);
    free(second_matrix);

    return 0;
}
