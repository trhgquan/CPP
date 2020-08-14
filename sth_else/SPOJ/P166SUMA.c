/**
 * P166SUMA - https://www.spoj.com/PTIT/problems/P166SUMA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    int has[5001] = {0}; int res = 0;
    for (int i = 1; i <= N; ++i) {int u; scanf("%d", &u); ++has[u];}
    for (int i = 1; i <= N; ++i) if (!has[i]) ++res;
    printf("%d", res);
    return 0;
}
