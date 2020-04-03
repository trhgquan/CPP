/**
 * NTH1 - https://www.spoj.com/problems/NTH1
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<stdlib.h>

int main() {
    // Solution goes here
    int x, y, t1, t2; scanf("%d%d%d%d", &x, &y, &t1, &t2);
    printf("%d", abs(t1 - x) + abs(t2 - y));

    return 0;
}
