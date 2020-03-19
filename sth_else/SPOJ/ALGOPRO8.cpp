/**
 * ALGOPRO8 - https://www.spoj.com/PTIT/problems/ALGOPRO8
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a + b) - max(a, b);
}

int main() {
    int a, b; scanf("%d%d", &a, &b);
    printf("%d %d", min(a, b), (max(a, b) - min(a, b)) / 2);
    return 0;
}
