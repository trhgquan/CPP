/**
 * PTIT014D - https://www.spoj.com/PTIT/problems/PTIT014D
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int isLucky(int a) {
    if (a == 0) return 0;

    int S = 0;
    while (a > 0) {S += a % 10; a /= 10;}
    if (S < 10) {
        if (S == 9) return 1;
        return 0;
    }
    return isLucky(S);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char number[201]; scanf("%s", number);
        int S = 0;
        for (unsigned i = 0; i < strlen(number); ++i) S += number[i] - 48;
        printf("%d\n", isLucky(S));
    }
    return 0;
}
