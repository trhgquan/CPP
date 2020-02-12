/**
 * P157PROA - https://www.spoj.com/PTIT/problems/P157PROA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N, A[1001] = {0};
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {int u; scanf("%d", &u); ++A[u];}

        int max = 0;
        int count_max = 0;
        for (int i = 1; i <= 1000; ++i){
            if (A[i] > count_max) {
                max = i;
                count_max = A[i];
            }
        }

        printf("%d\n", max);
    }

    return 0;
}
