/**
 * PTIT015A - https://www.spoj.com/PTIT/problems/PTIT015A
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>
#define NMAX 301 // 3 string, each max 100 -> max 300 + 1 = 301.

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// Use selection sort since small maximum array size (300).
void sort(int* A, int N) {
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            if (A[i] < A[j]) swap(&A[i], &A[j]);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N[NMAX]; int count = 0;
        for (int i = 1; i <= 3; ++i) {
            char u[NMAX]; scanf("%s", u);
            for (int i = strlen(u) - 1; i >= 0; --i) {
                N[count] = u[i] - 48;
                ++count;
            }
        }
        sort(N, count);
        for (int i = 0; i < count; ++i)
            printf("%d", N[i]);
        printf("\n");
    }
    return 0;
}
