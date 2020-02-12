/**
 * P142PROH - https://www.spoj.com/PTIT/problems/P142PROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    // Read and initialise
    int R, C; scanf("%d%d", &R, &C);
    char G[101][101];
    int row[101], col[101];
    for (int i = 0; i < R; ++i) row[i] = 1;
    for (int i = 0; i < C; ++i) col[i] = 1;
    for (int i = 0; i < R; ++i) scanf("%s", G[i]);

    // Mark all columns / rows that have strawberies
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (G[i][j] == 'S') {row[i] = 0; col[j] = 0;}

    // Count number of choco button can eat:
    int count = 0;

    for (int i = 0; i < R; ++i)
        if (row[i])
            for (int j = 0; j < C; ++j)
                if (G[i][j] != '#'){++count; G[i][j] = '#';}

    for (int i = 0; i < C; ++i)
        if (col[i])
            for (int j = 0; j < R; ++j)
                if (G[j][i] != '#'){++count; G[j][i] = '#';}

    printf("%d", count);
    return 0;
}
