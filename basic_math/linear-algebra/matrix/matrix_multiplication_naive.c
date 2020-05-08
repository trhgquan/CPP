/**
 * Matrix multiplication
 * Using dynamic memory allocation - CS102.
 * This is just a naive approach, for faster computing
 * on small-integer-matrices.
 *
 * Let A = R1xC1 matrix,
 *     B = R2xC2 matrix,
 * Result matrix, called D, will have the size R1xC2.
 *
 * INPUT:
 * First round will be four integers R1, C1, R2 and C2, space separated.
 * Next R1 rows, each row has C1 numbers, space separated.
 * Next R2 rows, each row has C2 integers, space separated.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * Read a RxC matrix.
 * @param m pointer to a matrix.
 * @param R rows of the matrix.
 * @param C columns of the matrix.
 */
void readMatrix(int** m, int R, int C) {
    for (int i = 0; i < R; ++i) {
        m[i] = (int*)malloc(sizeof(R) * C);
        for (int j = 0; j < C; ++j) scanf("%d", &m[i][j]);
    }
}

/**
 * This function print a matrix.
 * @param m pointer to matrix.
 * @param R rows of the matrix.
 * @param C columns of the matrix.
 */
void printMatrix(int** m, int R, int C) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            // Small output formatting:
            // Add a space before a positive integer to fit the column,
            // if that column has a negative.
            if (m[i][j] >= 0) printf(" ");
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

/**
 * Free a matrix,
 * (built this because there are 3 matrices
 * and I'm not gonna write 3 loops).
 * @param m pointer to the matrix
 * @param R the matrix's rows.
 */
void releaseMatrix(int** m, int R) {
    for (int i = 0; i < R; ++i)
        free(m[i]);
    free(m);
}

int main() {
    freopen("matrix_multiplication.inp", "r", stdin);

    // Get matrices row and column.
    int R1, C1, R2, C2; scanf("%d%d%d%d", &R1, &C1, &R2, &C2);

    // if C1 != R2 then we can't calculate,
    // and stop the program here.
    if (C1 != R2) {
        printf("Can't calculate with these inputs");
        return 0;
    }

    // Initalise two 2-d matrix, using dynamic memory allocation.
    int** result_matrix = (int**)malloc(R1);
    int** first_matrix  = (int**)malloc(R1);
    int** second_matrix = (int**)malloc(R2);

    // Get the first matrix, size RxC
    readMatrix(first_matrix, R1, C1);

    // Get the second Matrix, size CxR
    readMatrix(second_matrix, R2, C2);

    // Multiplies two matrices.
    // Since writing a function will requires too many parameters,
    // I'll not do that.
    for (int i = 0; i < R1; ++i) {
        result_matrix[i] = (int*)malloc(sizeof(R1) * C2);
        for (int j = 0; j < C2; ++j) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < R2; ++k)
                result_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
        }
    }

    // Print the result matrix.
    printMatrix(result_matrix, R1, C2);

    // Free first matrix
    releaseMatrix(first_matrix, R1);

    // Free second matrix
    releaseMatrix(second_matrix, R2);

    // Free result matrix
    releaseMatrix(result_matrix, R1);

    return 0;
}
