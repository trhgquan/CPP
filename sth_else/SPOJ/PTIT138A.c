/**
 * PTIT138A - https://www.spoj.com/PTIT/problems/PTIT138A
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    long a, b, c;
    while (1) {
        scanf("%ld%ld%ld", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;

        a = a * a; b = b * b; c = c * c;
        if (a + b == c || a + c == b || b + c == a)
            printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
