/**
 * BCPRIME - https://www.spoj.com/PTIT/problems/BCPRIME
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int isPrime(int a) {
    if (a == 0 || a == 1) return 0;
    if (a == 2) return 1;

    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0) return 0;
    return 1;
}

int main() {
    int N; scanf("%d", &N);
    if (isPrime(N)) printf("YES");
    else printf("NO");
    return 0;
}
