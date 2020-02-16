/**
 * PTITSU1D - https://www.spoj.com/PTIT/problems/PTITSU1D
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char G[501][501];
        int M, N; scanf("%d%d", &M, &N);
        for (int i = 0; i < 5 * M + 1; ++i)
        scanf("%s", G[i]);

        int count[5] = {0};
        for (int i = 1; i < 5 * M + 1; i += 5) {
            for (int j = 1; j < 5 * N + 1; j += 5){
            if (G[i + 3][j] == '*') ++count[4];
            else if (G[i + 2][j] == '*') ++count[3];
            else if (G[i + 1][j] == '*') ++count[2];
            else if (G[i][j] == '*') ++count[1];
            else ++count[0];
            }
        }

        for (int i = 0; i < 5; ++i) printf("%d ", count[i]);
        printf("\n");
    }
    return 0;
}
