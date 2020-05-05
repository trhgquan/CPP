/**
 * This program create a two-dimensional array
 * using dynamic memory allocator.
 *
 * CS102 Practice only.
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * This function print the array
 * @param m
 * @param R
 * @param C
 */
void printMatrix(int** m, int R, int C) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j)
            printf("%d ", m[i][j]);

        printf("\n");
    }
}

int main() {
    // Get the matrix's dimension
    int R, C; scanf("%d%d", &R, &C);

    // Create a 2-D dynamic array
    int** matrix = (int**)malloc(R);

    // Get the matrix (using C)
    for (int i = 0; i < R; ++i) {
        matrix[i] = (int*)malloc(sizeof(R) * C);
        for (int j = 0; j < C; ++j) scanf("%d", &matrix[i][j]);
    }

    // Print the matrix
    printMatrix(matrix, R, C);

    // Release the matrix
    for (int i = 0; i < R; ++i)
        free(matrix[i]);
    free(matrix);
    return 0;
}
