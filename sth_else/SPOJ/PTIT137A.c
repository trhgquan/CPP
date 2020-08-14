/**
 * PTIT137A - https://www.spoj.com/PTIT/problems/PTIT137A
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

int main() {
    while (1) {
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a == 0 && b == 0 && c == 0 && d == 0) break;

        int count = 0;
        while (a != b || a != c || a != d) {
            int x, y, z, t; x = abs(a - b); y = abs(b - c); z = abs(c - d); t = abs(d - a);
            a = x; b = y; c = z; d = t; ++count;
        }
        printf("%d\n", count);
    }
    return 0;
}
