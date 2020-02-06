/**
 * BCBEADS - https://www.spoj.com/PTIT/problems/BCBEADS
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int prev, now;
    int result = 0;
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &now);
        if (i > 1 && now != prev) ++result;
        prev = now;
    }
    printf("%d\n", result);
    return 0;
}
