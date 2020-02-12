/**
 * SSAM019B - https://www.spoj.com/PTIT/problems/SSAM019B
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        int A[N + 1]; for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);

        int found = 0; int pos = 0;
        for (int i = 1; i <= N - 1; ++i) {
            if (found) break;
            for (int j = i + 1; j <= N; ++j)
                if (A[i] == A[j]) {
                    found = 1;
                    pos = i;
                    break;
                }
        }

        if (found) printf("%d\n", A[pos]);
        else printf("NO\n");
    }
    return 0;
}
