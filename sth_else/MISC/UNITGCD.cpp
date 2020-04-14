/**
 * UNITGCD - https://www.codechef.com/APRIL20B/problems/UNITGCD
 * Codechef April Long Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    // Solution goes here
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        if (N > 1) printf("%d\n", N / 2);
        if (N <= 3 && N > 1) {
            printf("%d ", N);
            for (int i = 1; i <= N; ++i)
                printf("%d ", i);
            printf("\n");
        } else if (N > 3) {
            if (N % 2 != 0) {
                printf("3 1 2 3\n");
                for (int i = 4; i < N; i += 2)
                    printf("2 %d %d\n", i, i + 1);
            } else {
                printf("2 1 2\n");
                for (int i = 3; i < N; i += 2)
                    printf("2 %d %d\n", i, i + 1);
            }
        } else printf("1\n1 1\n");
    }

    return 0;
}
