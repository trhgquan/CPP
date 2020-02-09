/**
 * BCDAISY - https://www.spoj.com/PTIT/problems/BCDAISY
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int G[251][251];
int C[251] = {0};
int N, M;

void DFS(int u) {
    C[u] = 1;
    for (int i = 1; i <= N; ++i)
        if (G[i][u] == 1 && C[i] == 0 && i != u)
            DFS(i);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j)
            G[i][j] = 0;
    }

    for (int i = 1; i <= M; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }

    DFS(1);

    // This to got last 10pts: if no cows were "naughty",
    // print a zero.
    int have = 0;
    for (int i = 1; i <= N; ++i) {
        if (C[i] == 0) {
            have = 1;
            printf("%d\n", i);
        }
    }

    if (!have) printf("0\n");

    return 0;
}
