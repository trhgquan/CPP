/**
 * P17QPROH - https://www.spoj.com/PTIT/problems/P17QPROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

void swap(long* a, long *b) {
    long c = *a;
    *a = *b;
    *b = c;
}

void sort_asc(long* A, long N) {
    for (long i = 0; i < N - 1; ++i)
        for (long j = i + 1; j < N; ++j)
            if (A[i] > A[j]) swap(&A[i], &A[j]);
}

void sort_desc(long* A, long N) {
    for (long i = 0; i < N - 1; ++i)
        for (long j = i + 1; j < N; ++j)
            if (A[i] < A[j]) swap(&A[i], &A[j]);
}

int main() {
    long T; scanf("%ld", &T);
    for (long t = 1; t <= T; ++t) {
        long U[801], V[801]; long N; scanf("%ld", &N);
        for (long i = 0; i < N; ++i) scanf("%ld", &U[i]);
        for (long i = 0; i < N; ++i) scanf("%ld", &V[i]);
        sort_asc(U, N); sort_desc(V, N);
        long result = 0;
        for (long i = 0; i < N; ++i) result += U[i] * V[i];
        printf("Case #%ld: %ld\n", t, result);
    }
    return 0;
}
