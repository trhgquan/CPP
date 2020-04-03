/**
 * BCFACTOR - BCFACTOR
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int isPrime(long a) {
    if (a == 2) return 1;
    if (a < 2) return 0;
    for (long i = 2; i <= sqrt(a); ++i)
        if (a % i == 0) return 0;
    return 1;
}

int main() {
    // Solution goes here
    long N; scanf("%ld", &N);
    for (long i = 2; i <= sqrt(N); ++i)
        if (N % i == 0) {
            if (isPrime(i)) {
                long count = 0;
                while (N % i == 0) {
                    N /= i;
                    ++count;
                }
                printf("%ld %ld\n", i, count);
            }
        }
    if (N != 1 && isPrime(N)) printf("%ld 1\n", N);
    return 0;
}
