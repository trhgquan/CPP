/**
 * MAXARR1 - https://vn.spoj.com/problems/MAXARR1
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#define MAX 100001

int main() {
    int A[MAX], B[MAX];
    A[0] = 0; A[1] = 1;
    B[0] = 0; B[1] = 1;
    for (int i = 1; 2 * i + 1 < MAX; ++i) {
        A[2 * i] = A[i];
        A[2 * i + 1] = A[i] + A[i + 1];
    }
    for (int i = 2; i < MAX; ++i)
        if (A[i] > B[i - 1]) B[i] = A[i];
        else B[i] = B[i - 1];

    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        printf("%d\n", B[N]);
    }
    return 0;
}
