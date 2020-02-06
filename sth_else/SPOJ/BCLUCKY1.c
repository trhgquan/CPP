/**
 * BCLUCKY1 - https://www.spoj.com/PTIT/problems/BCLUCKY1
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int main() {
    char number[20]; scanf("%s", number);
    int count = 0;

    for (unsigned i = 0; i < strlen(number); ++i)
        if (number[i] == '4' || number[i] == '7') ++count;

    if (count == 4 || count == 7) printf("YES\n");
    else printf("NO\n");
    return 0;
}
