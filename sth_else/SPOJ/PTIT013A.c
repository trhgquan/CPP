/**
 * PTIT013A - https://www.spoj.com/PTIT/problems/PTIT013A
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char number[1001]; scanf("%s", number);
        if (number[strlen(number) - 1] == '6' &&
            number[strlen(number) - 2] == '8')
            printf("1\n");
        else printf("0\n");
    }
    return 0;
}
