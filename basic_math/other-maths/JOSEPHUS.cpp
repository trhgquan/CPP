// The Josephus algorithm.
#include <stdio.h>
#define lli long long int

lli N, M, C;

// There are plenty of ways to implement this algorithm.
// Here are some of it:
// Note: there are n people, with k steps each.
// Example problem: ANARC08H (SPOJ).

// Iterative way
lli josephus_iterative(lli n, lli k) {
    lli sum = 0;
    for (lli i = 2; i <= n; ++i)
        sum = (sum + k) % i;
    return sum + 1;
}

// Recursive way, but not works with big n and k.
lli josephus_recursive(lli n, lli k) {
    if (n == 1) return 1;
    return (josephus_recursive(n - 1, k) + k - 1) % n + 1;
}

int main() {
    while (1) {
        scanf("%I64d %I64d", &N, &M);
        if (N != 0 && M != 0) {
            // Use the way you want here
            lli result = josephus_recursive(N, M);

            printf("%I64d %I64d %I64d\n", N, M, result);
        } else break;
    }
    return 0;
}
