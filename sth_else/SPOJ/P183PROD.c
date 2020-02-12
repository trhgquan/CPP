/**
 * P183PROD - https://www.spoj.com/PTIT/problems/P183PROD
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int isPrime(int a) {
    if (a < 2) return 0;
    if (a == 2) return 1;
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0) return 0;
    return 1;
}

int main() {
    int N, M; scanf("%d%d", &N, &M);
    while (N--) {
        while (1){
            if (isPrime(M)) {
                printf("%d ", M);
                break;
            }
            else ++M;
        }
        ++M;
    }
    return 0;
}
