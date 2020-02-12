/**
 * P163PROD - https://www.spoj.com/PTIT/problems/P163PROD
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

long clearZero(long a) {
    // Clear all zeros - this makes the number goes backward
    long c = 0;
    while (a > 0) {
        if (a % 10 != 0)
            c = c * 10 + a % 10;
        a /= 10;
    }

    // Reverse the backward integer.
    long d = 0;
    while (c > 0) {
        d = d * 10 + c % 10;
        c /= 10;
    }
    return d;
}

int main() {
    long A, B; scanf("%ld%ld", &A, &B);
    long C = A + B;
    if (clearZero(A) + clearZero(B) == clearZero(C)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
