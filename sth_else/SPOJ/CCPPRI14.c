/**
 * CCPPRI14 - https://www.spoj.com/PTIT/problems/CCPPRI14
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int PRIME[2001] = {0}; for (int i = 2; i <= 2000; ++i) PRIME[i] = 1;
    for (int i = 2; i <= 2000; ++i)
        for (int j = 2; j * i <= 2000; ++j)
            if (PRIME[i * j]) PRIME[i * j] = 0;

    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        for (int i = 1; i <= 2000; ++i) {
            int x = i * i;
            if (PRIME[i] && x <= N) printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}
