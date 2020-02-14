/**
 * P163SUMH - https://www.spoj.com/PTIT/problems/P163SUMH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

int main() {
    int a, b; scanf("%d%d", &a, &b);
    int x = 0, y = 0, z = 0;
    for (int i = 1; i <= 6; ++i) {
        if (abs(i - a) < abs(i - b)) ++x;
        else if (abs(i - a) == abs(i - b)) ++y;
        else ++z;
    }

    printf("%d %d %d", x, y, z);
    return 0;
}
