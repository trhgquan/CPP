/**
 * PTIT013K - https://www.spoj.com/PTIT/problems/PTIT013K
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    int factorial[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    int T; scanf("%d", &T);
    while (T--) {
        char num[11]; scanf("%s", num);
        long ans = 0;
        for (int i = strlen(num) - 1; i >= 0; --i)
            ans += (num[i] - 48) * (factorial[strlen(num) - i]);
        printf("%ld\n", ans);
    }

    return 0;
}
