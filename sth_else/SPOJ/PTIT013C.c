/**
 * PTIT013C - https://www.spoj.com/PTIT/problems/PTIT013C
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        long x, y, z, t; scanf("%ld%ld%ld%ld", &x, &z, &y, &t);
        long u = (x - y) * (x - y);
        long v = (-abs(z) - abs(t)) * (-abs(z) - abs(t));
        printf("%ld\n", (long)sqrt(u + v));
    }
    return 0;
}
