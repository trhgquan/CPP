/**
 * P156PROE - https://www.spoj.com/PTIT/problems/P156PROE
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    freopen("input.txt", "r", stdin);
    char keys[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

    while (1) {
        int N; char string[41]; scanf("%d %s", &N, string);

        if (N == 0) break;

        printf("%d %s\n", N, string);
    }
    return 0;
}
