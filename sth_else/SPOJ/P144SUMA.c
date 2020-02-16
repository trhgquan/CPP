/**
 * P144SUMA - https://www.spoj.com/PTIT/problems/P144SUMA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    int N; scanf("%d", &N);
    int count = 0;
    char now[3] = "", prev[3] = "";
    for (int i = 1; i <= N; ++i) {
        scanf("%s", now);
        if (strcmp(now, prev) != 0) ++count;
        strcpy(prev, now);
    }
    printf("%d", count);
    return 0;
}
