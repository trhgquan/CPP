/**
 * BCCOM - https://www.spoj.com/PTIT/problems/BCCOM
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);

    while (T--) {
        int N; scanf("%d", &N);
        int S;
        while (1) {
            S = 0;
            while (N > 0) {S += N % 10; N /= 10;}
            if (S >= 10) N = S;
            else break;
        }
        printf("%d\n", S);
    }

    return 0;
}
