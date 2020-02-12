/**
 * P161SUMH - https://www.spoj.com/PTIT/problems/P161SUMH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#define NMAX 101

int DFS(int u, int v, char G[NMAX][NMAX], int N) {
    int count = 0;

    if (u - 1 >= 0 && G[u - 1][v] == 'o') ++count;
    if (v - 1 >= 0 && G[u][v - 1] == 'o') ++count;
    if (u + 1 < N && G[u + 1][v] == 'o') ++count;
    if (v + 1 < N && G[u][v + 1] == 'o') ++count;

    return ((count > 0 && count % 2 == 0) || (count == 0));
}

int main() {
    int N; scanf("%d", &N);
    char G[NMAX][NMAX];
    for (int i = 0; i < N; ++i) scanf("%s", G[i]);

    int can = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!DFS(i, j, G, N)) {can = 0; break;}

    if (can) printf("YES\n");
    else printf("NO\n");

    return 0;
}
