/**
 * CPPCOM01 - https://www.spoj.com/PTIT/problems/CPPCOM01
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

void Try(int* X, int N, int i) {
    for (int j = 0; j <= 1; ++j) {
        X[i] = j;

        if (i == N) {
            for (int i = 1; i <= N; ++i) {
                printf("%d", X[i]);
            } printf(" ");
        } else Try(X, N, i + 1);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        int A[N + 1];
        Try(A, N, 1);
        printf("\n");
    }
    return 0;
}
