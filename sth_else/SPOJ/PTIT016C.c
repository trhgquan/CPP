/**
 * PTIT016C - https://www.spoj.com/PTIT/problems/PTIT016C
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char N[2001]; scanf("%s", N);
        int can = 1;
        for (unsigned i = 1; i <= strlen(N); ++i) {
            if ((i % 2 != 0 && (N[i - 1] - 48) % 2 == 0) ||
                (i % 2 == 0 && (N[i - 1] - 48) % 2 != 0)) {
                    can = 0;
                    break;
            }
        }
        if (can) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
