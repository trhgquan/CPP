/**
 * CPPCOM03 - https://www.spoj.com/PTIT/problems/CPPCOM03
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

void Try(int* X, int* A, int* F, int N, int i) {
    for (int j = 1; j <= N; ++j) {
        if (F[j]) {
            F[j] = 0;
            A[i] = j;
            if (i == N) {
                for (int k = 1; k <= N; ++k) printf("%d", A[k]);
                printf(" ");
            } else Try(X, A, F, N, i + 1);
            F[j] = 1;
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        int X[N + 1], F[N + 1]; for (int i = 1; i <= N; ++i) {X[i] = i; F[i] = 1;};
        int A[N + 1];
        Try(X, A, F, N, 1);
        printf("\n");
    }
    return 0;
}
