/**
 * PRISUSTR - https://www.spoj.com/PTIT/problems/PRISUSTR
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    // Sieve of Eratosthenes
    int PRIME[100001]; for (int i = 2; i <= 100000; ++i) PRIME[i] = 1;
    PRIME[0] = 0, PRIME[1] = 0;
    for (int i = 2; i <= 100000; ++i)
        for (int j = 2; i * j <= 100000; ++j) if (PRIME[i * j]) PRIME[i * j] = 0;

    char S[256];
    while (1) {
        scanf("%s", S);
        if (strlen(S) == 1 && S[0] == '0') break;
        int max = 2;

        for (unsigned i = 0; i < strlen(S) - 4; ++i) {
            int N = 0;
            for (unsigned j = i; j <= i + 4; ++j) {
                N = N * 10 + (S[j] - 48);
                if (PRIME[N] && N > max) max = N;
            }
        }

        printf("%d\n", max);
    }
    return 0;
}
