/**
 * P152SUMG - https://www.spoj.com/PTIT/problems/P152SUMG
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    // Build a sieve
    int PRIME[51];
    for (int i = 0; i <= 50; ++i) PRIME[i] = 1;
    for (int i = 2; i <= 50; ++i)
        for (int j = 2; j * i <= 50; ++j)
            if (PRIME[i * j]) PRIME[i * j] = 0;

    int x, y; scanf("%d%d", &x, &y);
    int can = 1;
    for (int i = x + 1; i < y; ++i)
        if (PRIME[i]) {can = 0; break;}
    if (can && PRIME[y]) printf("YES\n");
    else printf("NO\n");
    return 0;
}
