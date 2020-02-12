/**
 * P183SUMJ - https://www.spoj.com/PTIT/problems/P183SUMJ
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    // Inputs
    int N, M; scanf("%d%d", &N, &M);
    int X[10]; int Y[10];
    for (int i = 1; i <= N; ++i) scanf("%d", &X[i]);
    for (int i = 1; i <= M; ++i) {int u; scanf("%d", &u); Y[u] = 1;}

    
    for (int i = 1; i <= N; ++i)
        if (Y[X[i]] == 1)
            printf("%d ", X[i]);
    printf("\n");
    return 0;
}
