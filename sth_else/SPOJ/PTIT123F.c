/**
 * PTIT123F - https://www.spoj.com/PTIT/problems/PTIT123F
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        int ROOM[101] = {0};
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j * i <= N; ++j)
                if (ROOM[i * j] == 1) ROOM[i * j] = 0;
                else ROOM[i * j] = 1;
        }

        int ans = 0;
        for (int i = 1; i <= N; ++i) ans += ROOM[i];
        printf("%d\n", ans);
    }
    return 0;
}
