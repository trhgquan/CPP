/**
 * P165SUMI - https://www.spoj.com/PTIT/problems/P165SUMI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    long N; scanf("%ld", &N);
    long ans;

    if (N % 2 == 0)
        ans = N / 2;
    else ans = ((N / 2) + 1) * -1;

    printf("%ld\n", ans);
    return 0;
}
