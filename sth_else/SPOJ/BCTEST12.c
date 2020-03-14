/**
 * BCTEST12 - https://www.spoj.com/PTIT/problems/BCTEST12
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

char toLower(char a) {
    if (a >= 'A' && a <= 'Z') return a + 32;
    return a;
}

int main() {
    char S[1001]; scanf("%s", S);
    for (unsigned i = 0; i < strlen(S); ++i) {
        char chr = toLower(S[i]);
        if (chr == 'a' || chr == 'e' || chr == 'o' || chr == 'u' || chr == 'i' || chr == 'y')
            continue;
        else printf(".%c", chr);
    }
    return 0;
}
