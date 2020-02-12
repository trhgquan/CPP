/**
 * P166SUMI - https://www.spoj.com/PTIT/problems/P166SUMI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int u; scanf("%d", &u);
        if (u == 0) ++count;
    }
    if (count == 1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
