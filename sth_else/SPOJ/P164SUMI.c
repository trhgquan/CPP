/**
 * P164SUMI - https://www.spoj.com/PTIT/problems/P164SUMI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n + 1]; int c = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i){
        if (a[i] > 0 && a[i] >= a[k]) ++c;
    }
    printf("%d\n", c);
    return 0;
}
