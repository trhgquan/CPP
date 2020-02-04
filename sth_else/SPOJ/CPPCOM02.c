/**
 * CPPCOM02 - https://www.spoj.com/PTIT/problems/CPPCOM02
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

void Try(int* X, int* F, int N, int K, int i) {
    for (int j = X[i - 1] + 1; j <= N - K + i; ++j) {
        if (F[j]) {
            F[j] = 0;
            X[i] = j;
            if (i == K) {
                for (int k = 1; k <= K; ++k) printf("%d", X[k]);
                printf(" ");
            } else Try(X, F, N, K, i + 1);
            F[j] = 1;
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, K; scanf("%d%d", &N, &K);
        int X[K + 1], F[N + 1]; for (int i = 1; i <= N; ++i) F[i] = 1;
        X[0] = 0;
        Try(X, F, N, K, 1);
        printf("\n");
    }
    return 0;
}
