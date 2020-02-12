/**
 * PTIT015I - https://www.spoj.com/PTIT/problems/PTIT015I
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, E; scanf("%d%d", &N, &E);
        int S = 0, max = 0;
        for (int i = 1; i <= N; ++i) {
            int u; scanf("%d", &u);
            if (S + u <= E) ++max;
            S += u;
        }
        printf("%d\n", max);
    }
    return 0;
}
