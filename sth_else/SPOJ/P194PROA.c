/**
 * P194PROA - https://www.spoj.com/PTIT/problems/P194PROA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        if ((u == 1 && v == 1) ||
            (u == 1 && w == 1) ||
            (v == 1 && w == 1)) ++count;
    }
    printf("%d\n", count);
    return 0;
}
