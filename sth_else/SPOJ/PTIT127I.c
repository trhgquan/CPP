/**
 * PTIT127I - https://www.spoj.com/PTIT/problems/PTIT127I
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    while (1) {
        int N; scanf("%d", &N);
        if (N == 0) break;

        int num[50] = {0};
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= 6; ++j)
                {int u; scanf("%d", &u); num[u] = 1;}

        int all = 1;
        for (int i = 1; i <= 49; ++i)
            if (num[i] == 0) {all = 0; break;}

        if (!all) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
