/**
 * P192PROB - https://www.spoj.com/PTIT/problems/P192PROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    int a = 1, b = 2, c = 3;
    int i;
    for (i = 0; i <= y; ++i) {
        if (a + i < x && b + i < y && c + i < z) continue;
        else break;
    }
    printf("%d", a + b + c + 3 * i);
    return 0;
}
