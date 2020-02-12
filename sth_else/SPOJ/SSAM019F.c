/**
 * SSAM019F - https://www.spoj.com/PTIT/problems/SSAM019F
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    unsigned long long F[101] = {0};
    F[0] = 0; F[1] = 1; F[2] = 1;
    for (int i = 2; i < 101; ++i) F[i] = F[i - 1] + F[i - 2];

    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        printf("%llu\n", F[N]);
    }
    return 0;
}
