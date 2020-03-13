/**
 * CPPPRI03 - https://www.spoj.com/PTIT/problems/CPPPRI03
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int PRIME[10001]; PRIME[1] = 0; for (int i = 2; i < 10001; ++i) PRIME[i] = 1;
    for (int i = 2; i < 10001; ++i)
        for (int j = 2; j * i < 10001; ++j)
            if (PRIME[i * j]) PRIME[i * j] = 0;
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        for (int i = 2; i <= N; ++i)
            if (PRIME[i]) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
