/**
 * Another implementation of Gauss-Jordan elimination,
 *
 *
 * This implementation belongs to Bui The Tam, PhD
 * His full video, you can find here:
 * https://www.youtube.com/watch?v=-ynLuerBzHA
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * Print the matrix
 */
void printMatrix(double* a, int N) {
    for (int i = 1; i <= N * (N + 1); i++){
        printf("%.2lf ", a[i]);
        if (i % (N + 1) == 0) printf("\n");
    }
}

/**
 * Using the Gaussian Elimination Method to solve linear systems.
 * (This using a one-dimensional array for faster process).
 */
int LinearSystem(double* a, int n) {
    int i, j, k, ni, nj, n1; double s; n1 = n + 1; ni = nj = 0;

    for (j = 1; j <= n; j++) {
        ni = nj;
        for (i = j; i <= n; i++) {
            if (fabs(a[ni + j]) > 0.0001) goto l1;
            ni += n1;
        }
        return 0;

        l1:
        for (k = 1; k <= n1; k++) {
            s = a[nj + k];
            a[nj + k] = a[ni + k];
            a[ni + k] = s;
        };
        s = 1.0 / a[nj + j];
        for (k = 1; k <= n1; k++)
            a[nj + k] = s * a[nj + k];
        ni = 0;
        for (i = 1; i <= n; i++) {
            if (i != j) {
                s = -a[ni + j];
                for (k = 1; k <= n1; k++)
                    a[ni + k] += s * a[nj + k];
            }
            ni += n1;
        }
        nj += n1;
    }
    return 1;
}

int main() {
    freopen("equations.inp", "r+", stdin);
    freopen("GJ-02.out", "w+", stdout);

    // Read number of variables.
    int N; scanf("%d", &N);
    // One-dimensional matrix array.
    double matrix[N * (N + 1) + 1];
    for (int i = 1; i <= N * (N + 1); i++) scanf("%lf", &matrix[i]);

    // printMatrix(matrix, m);
    int result = LinearSystem(matrix, N);

    printf("Final augmented matrix:\n");
    printMatrix(matrix, N);

    if (result == 0) printf("Infinite solutions or No solution.\n");
    else {
        printf("Solutions: ");
        int k = N + 1;
        for (int i = 1; i <= N; i++){
            printf("%.2lf ", matrix[k]);
            k += N + 1;
        }
    }

    return 0;
}
