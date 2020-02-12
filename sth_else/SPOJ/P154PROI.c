/**
 * P154PROI - https://www.spoj.com/PTIT/problems/P154PROI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char string[100001]; scanf("%s", string);
        int can = 1;
        for (unsigned i = 1; i <= strlen(string) / 2; ++i)
            if (abs(string[i] - string[i - 1]) != abs(string[strlen(string) - i] - string[strlen(string) - i - 1])) {can = 0; break;}

        if (can) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
