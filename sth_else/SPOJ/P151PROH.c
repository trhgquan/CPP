/**
 * P151PROH - https://www.spoj.com/PTIT/problems/P151PROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    char input[21]; scanf("%s", input);
    int can = 1;

    for (unsigned i = 0; i < strlen(input); ++i) {
        if (input[i] != '4' && input[i] != '1') {can = 0; break;}
        else {
            if (input[i] == '1') continue;
            if (i > 0 && input[i] == '4' && input[i - 1] == '1') continue;
            if (i > 1 && input[i] == '4' && input[i - 1] == '4' && input[i - 2] == '1') continue;
            else {can = 0; break;}
        }
    }

    if (can) printf("YES");
    else printf("NO");

    return 0;
}
