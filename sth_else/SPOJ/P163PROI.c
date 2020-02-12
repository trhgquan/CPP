/**
 * P163PROI - https://www.spoj.com/PTIT/problems/P163PROI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    int x = a + b + c;
    int y = 2 * (a + c);
    int z = 2 * (b + c);
    int t = 2 * (a + b);
    printf("%d\n", min(x, min(y, min(z, t))));
    return 0;
}
