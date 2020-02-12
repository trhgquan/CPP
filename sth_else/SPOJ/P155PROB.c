/**
 * P155PROB - https://www.spoj.com/PTIT/problems/P155PROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int X, S; scanf("%d%d", &X, &S); X *= S;
    for (int i = 1; i <= 5; ++i) {
        scanf("%d", &S); printf("%d ", S - X);
    }
    return 0;
}
