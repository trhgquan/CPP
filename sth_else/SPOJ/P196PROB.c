/**
 * P196PROB - https://www.spoj.com/PTIT/problems/P196PROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int* A) {
    for (int i = 0 ; i < 2; ++i)
        for (int j = i + 1; j < 3; ++j)
            if (A[i] > A[j]) swap(&A[i], &A[j]);
}

int main() {
    int A[3]; scanf("%d%d%d", &A[0], &A[1], &A[2]);
    sort(A);

    printf("%d", A[1] - A[0] + A[2] - A[1]);
    return 0;
}
