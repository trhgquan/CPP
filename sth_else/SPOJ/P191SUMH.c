/**
 * P191SUMH - https://www.spoj.com/PTIT/problems/P191SUMH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    int N; scanf("%d", &N);
    char G[51][51];
    for (int i = 1; i <= N; ++i) {scanf("%s", G[i - 1]);}

    for (int i = 1; i < N - 1; ++i){
        for (int j = 1; j < N - 1; ++j)
            if (G[i][j] == '.' &&
                G[i - 1][j] == '.' &&
                G[i + 1][j] == '.' &&
                G[i][j - 1] == '.' &&
                G[i][j + 1] == '.') {
                    G[i][j] = '#';
                    G[i - 1][j] = '#';
                    G[i + 1][j] = '#';
                    G[i][j - 1] = '#';
                    G[i][j + 1] = '#';
                }
    }

    int can = 1;
    for (int i = 0; i < N; ++i) {
        if (!can) break;
        for (int j = 0; j < N; ++j)
            if (G[i][j] == '.') {can = 0; break;}
    }

    if (can) printf("YES");
    else printf("NO");

    return 0;
}
