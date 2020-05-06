/**
 * Matrix multiplication
 * Using dynamic memory allocation - CS102.
 * This is just a naive approach, for faster computing
 * on small-integer-matrices.
 *
 * Let A = nxm matrix,
 *     B = mxn matrix,
 * Result matrix, called C, will have the size nxn.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * This function print a matrix.
 * @param m pointer to matrix.
 * @param R rows of the matrix.
 * @param C columns of the matrix.
 */
void printMatrix(int** m, int R, int C) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main() {
    freopen("matrices.inp", "r", stdin);

    // Get matrices row and column.
    int R, C; scanf("%d%d", &R, &C);

    // Initalise two 2-d matrix, using dynamic memory allocation.
    int** first_matrix  = (int**)malloc(R);
    int** second_matrix = (int**)malloc(C);
    int** result_matrix = (int**)malloc(R);

    // Get the first matrix, size RxC
    for (int i = 0; i < R; ++i) {
        first_matrix[i] = (int*)malloc(sizeof(R) * C);
        for (int j = 0; j < C; ++j) scanf("%d", &first_matrix[i][j]);
    }

    // Get the second Matrix, size CxR
    for (int i = 0; i < C; ++i) {
        second_matrix[i] = (int*)malloc(sizeof(C) * R);
        for (int j = 0; j < R; ++j) scanf("%d", &second_matrix[i][j]);
    }

    // Multiplies two matrices.
    for (int i = 0; i < R; ++i) {
        result_matrix[i] = (int*)malloc(sizeof(R) * R);
        for (int j = 0; j < R; ++j) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < C; ++k)
                result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
        }
    }

    // Print the result matrix.
    printMatrix(result_matrix, R, R);

    // Release the first Matrix
    for (int i = 0; i < R; ++i) free(first_matrix[i]);
    free(first_matrix);

    // Release the second Matrix
    for (int i = 0; i < C; ++i) free(second_matrix[i]);
    free(second_matrix);

    // Release the result matrix
    for (int i = 0; i < R; ++i) free(result_matrix[i]);
    free(result_matrix);

    return 0;
}
