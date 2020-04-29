/**
 * Gauss-Jordan elimination method implementation in C++
 * Code from GeeksforGeeks.
 * https://www.geeksforgeeks.org/program-for-gauss-jordan-elimination-method/
 *
 * Caution: this works only with matrix size N x (N + 1).
 * This is the best implementation that I can find so far.
 */

#include<bits/stdc++.h>
#define matrixType vector<vector<double>>
using namespace std;

/**
 * This function print the matrix
 * (Elements are printed in 2-digits double).
 */
void printMatrix(matrixType matrix, int N) {
    for (int i = 0; i < N; ++i){
        for (int j = 0; j <= N; ++j)
            printf("%.2lf ", matrix[i][j]);
        printf("\n");
    }
}

/**
 * This function check whether infinite solutions
 * exists or no solution exists.
 */
int checkConsistency(matrixType matrix, int N, int flag) {
    int i, j;
    double sum;

    // Flag = 2 is infinite solution
    // Flag = 3 is no solution
    flag = 3;

    for (i = 0; i < N; ++i){
        sum = 0;
        for (j = 0; j < N; ++j)
            sum += matrix[i][j];

        if (sum == matrix[i][j]) flag = 2;
    }

    return flag;
}

/**
 * This function reduce matrix
 * to reduced row echelon form.
 */
int performOperation(matrixType& matrix, int N) {
    int i, j, k = 0;
    int c;
    int flag = 0;

    // Performing elementary operations.
    for (i = 0; i < N; ++i) {
        if (matrix[i][i] == 0) {
            c = 1;
            while ((i + c) < N && matrix[i + c][i] == 0)
                ++c;
            if ((i + c) == N) {
                flag = 1; break;
            }

            for (j = i, k = 0; k <= N; ++k)
                swap(matrix[j][k], matrix[j + c][k]);
        }

        for (j = 0; j < N; ++j) {
            if (i != j) {
                // Converting matrix to reduced row echelon form (diagonal matrix)
                double pro = matrix[j][i] / matrix[i][i];

                for (k = 0; k <= N; ++k)
                    matrix[j][k] = matrix[j][k] - matrix[i][k] * pro;
            }
        }
    }

    return flag;
}

void printResult(matrixType matrix, int N, int flag) {
    if (flag == 2) printf("Infinite solution\n");
    else if (flag == 3) printf("No solution\n");
    else {
        printf("Solutions: ");

        // Print the solution by dividing constants
        // by their respective diagonal elements.
        for (int i = 0; i < N; ++i)
            printf("%.2lf ", matrix[i][N] / matrix[i][i]);
    }
}

int main() {
    freopen("equations.inp", "r+", stdin);
    freopen("gj-result.out", "w+", stdout);

    // Read number of variables.
    int N; scanf("%d", &N);

    matrixType matrix(N, vector<double>(N + 1, 0));

    // Read matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= N; ++j)
            scanf("%lf", &matrix[i][j]);

    int flag = 1;

    // Performing the matrix transformation
    flag = performOperation(matrix, N);
    if (flag) flag = checkConsistency(matrix, N, flag);

    // Print the final augmented matrix
    printf("Final augmented matrix:\n");
    printMatrix(matrix, N);

    // Print the final result
    printResult(matrix, N, flag);
    return 0;
}
