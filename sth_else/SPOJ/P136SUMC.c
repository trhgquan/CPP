/**
 * P136SUMC - https://www.spoj.com/PTIT/problems/P136SUMC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int reverse(int a) {
    int r = 0;
    while (a > 0) {r = r * 10 + a % 10; a /= 10;}
    return r;
}

int main() {
    int A, B; scanf("%d%d", &A, &B); A = reverse(A); B = reverse(B);
    if (A > B) printf("%d", A);
    else printf("%d", B);
    return 0;
}
