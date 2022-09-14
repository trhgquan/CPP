/**
 * QBMAX - https://vn.spoj.com/problems/QBMAX/
 * Codeforces: https://codeforces.com/group/FLVn1Sc504/contest/274711/problem/J
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<stdio.h>
#include<stdlib.h>

int table[121][121];
int value[121][121];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, M; scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j){
            scanf("%d", &table[i][j]);
        }
        value[i][1] = table[i][1];
    }

    for (int i = 1; i <= N; ++i) {
        value[i][1] = table[i][1];
    }

    for (int j = 2; j <= M; ++j) {
        for (int i = 1; i <= N; ++i){
            // This to prevent setting borders to 0,
            // which is not accurate when the table is full of negative integers.
            if (i == 1) {
                value[i][j] = max(value[i][j - 1], value[i + 1][j - 1]) + table[i][j];
            }
            else if (i == N) {
                value[i][j] = max(value[i - 1][j - 1], value[i][j - 1]) + table[i][j];
            }
            else value[i][j] = max(value[i - 1][j - 1], max(value[i][j - 1], value[i + 1][j - 1])) + table[i][j];
        }
    }

    int res = value[1][M];
    for (int i = 1; i <= N; ++i) {
        if (value[i][M] > res) res = value[i][M];
    }

    printf("%d", res);
    return 0;
}
