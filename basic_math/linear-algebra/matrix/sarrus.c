/**
 * Using sarrus construction to calculate determinant of 3x3 matrices.
 * Matrix must be a square, 3x3 size/ *
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/**
 * This function read a matrix from stdin.
 *
 * @param matrix pointer to the matrix.
 */
void readMatrix(int** matrix) {
    for (int i = 0; i < 3; ++i) {
        matrix[i] = (int*)malloc(sizeof(int) * 5);
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &matrix[i][j]);
            if (j < 2) matrix[i][j + 3] = matrix[i][j];
        }
    }
}

/**
 * This function print a matrix.
 *
 * @param matrix pointer to the matrix.
 */
void printMatrix(int** matrix) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

/**
 * This function use the Sarrus Rule to calculate
 * determinant of a 3x3 matrix.
 *
 * @param matrix pointer to the matrix.
 */
void SarrusRule(int** matrix) {
    int sumPositive, sumNegative; sumPositive = sumNegative = 0;

    // Calculate diagonals.
    for (int i = 0; i < 3; ++i)
        sumPositive += matrix[0][i] * matrix[1][i + 1] * matrix[2][i + 2];
    // Calculate anti-diagonals.
    for (int i = 0; i < 3; ++i)
        sumNegative += matrix[2][i] * matrix[1][i + 1] * matrix[0][i + 2];

    // Print the result.
    printf("det(A) = %d\n", abs(sumPositive - sumNegative));
}

/**
 * This function free dynamic allocated memory.
 * @param matrix pointer to the matrix.
 */
void freeMatrix(int** matrix) {
    for (int i = 0; i < 3; ++i) free(matrix[i]);
    free(matrix);
}

int main() {
    freopen("sarrus.inp", "r", stdin);

    // Create a dynamic-allocated matrix.
    int** matrix = (int**)malloc(sizeof(int) * 3);

    // Read datas
    readMatrix(matrix);

    // Print the Matrix
    printMatrix(matrix);

    // Calculate determinant, using Sarrus rule.
    SarrusRule(matrix);

    // Free matrix.
    freeMatrix(matrix);
    return 0;
}
