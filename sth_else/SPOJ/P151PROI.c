/**
 * P151PROI - https://www.spoj.com/PTIT/problems/P151PROI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int compress(int A) {
    if (A < 10) return A;
    int S = 0;
    while (A > 0) {S += A % 10; A /= 10;}
    return compress(S);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        printf("%d\n", compress(N));
    }
    return 0;
}
