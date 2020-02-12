/**
 * P191PROB - https://www.spoj.com/PTIT/problems/P191PROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N, M; scanf("%d%d", &N, &M);
    int A[5001];
    for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    int count = 0;
    for (int i = 1; i < N; ++i)
        for (int j = i + 1; j <= N; ++j)
            if (A[i] + A[j] == M) ++count;
    printf("%d\n", count);
    return 0;
}
