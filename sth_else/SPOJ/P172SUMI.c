/**
 * P172SUMI - https://www.spoj.com/PTIT/problems/P172SUMI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    long A[N + 1];
    long max = 0, sum = 0;

    for (int i = 1; i <= N; ++i) {
        scanf("%ld", &A[i]);
        sum += A[i];
    }

    if (sum % 2 != 0) max = sum;
    else {
        for (int i = 1; i <= N; ++i) {
            if ((sum - A[i]) > max && (sum - A[i]) % 2 != 0)
                max = sum - A[i];
        }
    }

    printf("%ld\n", max);
    return 0;
}
