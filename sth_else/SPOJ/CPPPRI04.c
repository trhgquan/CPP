/**
 * CPPPRI04 - https://www.spoj.com/PTIT/problems/CPPPRI04
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int main() {
    int PRIME[10001]; for (int i = 2; i < 10001; ++i) PRIME[i] = 1;
    for (int i = 2; i < 10001; ++i)
        for (int j = 2; j * i < 10001; ++j)
            if (PRIME[i * j]) PRIME[i * j] = 0;
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        printf("1 ");
        for (int i = 2; i <= N; ++i){
            if (PRIME[i]) printf("%d ", i);
            else {
                for (int j = 2; j <= sqrt(i); ++j)
                    if (PRIME[j] && i % j == 0){
                        printf("%d ", j);
                        break;
                    }
            }
        }
        printf("\n");
    }
    return 0;
}
