/**
 * PTIT136B - https://www.spoj.com/PTIT/problems/PTIT136B
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int R, C; scanf("%d%d", &R, &C);
    char G[2 * R + 1][2 * C + 1];

    for (int i = 0; i < R; ++i)
        scanf("%s", G[i]);

    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j) {
            G[2 * R - i - 1][j] = G[i][j];
            G[i][2 * C - j - 1] = G[i][j];
            G[2 * R - i - 1][2 * C - j - 1] = G[i][j];
        }
    }

    int n, m; scanf("%d%d", &n, &m);

    for (int i = 0; i < 2 * R; ++i){
        for (int j = 0; j < 2 * C; ++j){
            if (i == n - 1 && j == m - 1) {
                if (G[i][j] == '.') printf("#");
                else printf(".");
            }
            else printf("%c", G[i][j]);
        }
        printf("\n");
    }

    return 0;
}
