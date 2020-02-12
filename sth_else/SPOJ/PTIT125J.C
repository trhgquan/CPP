/**
 * PTIT125J - https://www.spoj.com/PTIT/problems/PTIT125J
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    char G[31][31];
    for (int i = 0; i < N; ++i)
        scanf("%s", G[i]);

    int found = 0;
    for (int i = 0; i < N; ++i){
        if (found) break;
        for (int j = 0; j < N; ++j)
            if (G[i][j] != '.' &&
                ((G[i][j] == G[i + 1][j] && G[i + 1][j] == G[i + 2][j]) ||
                (G[i][j] == G[i + 1][j + 1] && G[i + 1][j + 1] == G[i + 2][j + 2]) ||
                (G[i][j] == G[i][j + 1] && G[i][j + 1] == G[i][j + 2]) ||
                (G[i][j] == G[i - 1][j + 1] && G[i - 1][j + 1] == G[i - 2][j + 2]))) {
                    printf("%c", G[i][j]);
                    found = 1;
                    break;
                }
    }

    if (!found) printf("ongoing");

    return 0;
}
