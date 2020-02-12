/**
 * P155SUMF - https://www.spoj.com/PTIT/problems/P155SUMF
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    int B[102];
    for (int i = 1; i <= N; ++i) scanf("%d", &B[i]);

    int A[102];
    A[1] = B[1];
    for (int i = 2; i <= N; ++i)
        A[i] = i * B[i] - (i - 1) * B[i - 1];

    for (int i = 1; i <= N; ++i) printf("%d ", A[i]);
    printf("\n");

    return 0;
}
