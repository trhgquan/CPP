/**
 * BCPALIN - https://www.spoj.com/PTIT/problems/BCPALIN
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        int P = N, Q = 0;
        while (N > 0) {
            Q = Q * 10 + N % 10;
            N /= 10;
        }

        if (P == Q) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
