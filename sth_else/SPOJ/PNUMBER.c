// PROBLEM:
// https://vn.spoj.com/problems/PNUMBER/
// Approach: Sieve of Eratosthenes, normal loop.
/* For Sieve of Eratosthenes, find Eratosthenes.cpp in basic_math. */
#include <stdio.h>

int PRIME[200001];

void Init() {
    for (int i = 2; i <= 200001; ++i)
        PRIME[i] = 1;
    PRIME[1] = 0;
    for (int i = 2; i <= 20001; ++i)
        for (int j = 2; j * i <= 200001; ++j)
            if (PRIME[i * j]) PRIME[i * j] = 0;
}

int main() {
    int A, B;
    Init();
    scanf("%d %d", &A, &B);
    for (int i = A; i <= B; ++i)
        if (PRIME[i]) printf("%d\n", i);
    return 0;
}
