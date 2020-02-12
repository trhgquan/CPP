/**
 * PTIT121I - https://www.spoj.com/PTIT/problems/PTIT121I
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int K, N; scanf("%d%d", &K, &N);
        char S[101]; scanf("%s", S);
        printf("%d ", K);
        for (unsigned i = 0; i < strlen(S); ++i)
            for (int j = 1; j <= N; ++j) printf("%c", S[i]);
        printf("\n");
    }
    return 0;
}
