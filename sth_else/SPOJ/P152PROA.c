/**
 * P152PROA - https://www.spoj.com/PTIT/problems/P152PROA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int isPrime(int a) {
    if (a == 2) return 1;
    if (a < 2) return 0;
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0) return 0;
    return 1;
}

int GCD(int a, int b) {
    while (a % b != 0){
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int x; scanf("%d", &x);
        int res = 0;
        for (int i = 1; i <= x; ++i)
            if (GCD(i, x) == 1) ++res;
        printf("%d\n", isPrime(res));
    }
    return 0;
}
