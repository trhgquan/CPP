/**
 * CPPPRI05 - https://www.spoj.com/PTIT/problems/CPPPRI05
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int PRIME[10001]; for (int i = 1; i <= 10000; ++i) PRIME[i] = 1;
    PRIME[1] = 0;
    for (int i = 2; i < 10001; ++i)
        for (int j = 2; j * i < 10001; ++j)
            if (PRIME[i * j]) PRIME[j * i] = 0;
    int T; scanf("%d", &T);
    while (T--) {
        int M, N; scanf("%d%d", &M, &N);
        for (int i = M; i <= N; ++i)
            if (PRIME[i]) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
