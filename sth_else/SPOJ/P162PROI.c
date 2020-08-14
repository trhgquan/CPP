/**
 * P162PROI - https://www.spoj.com/PTIT/problems/P162PROI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

int char2int(char* str) {
    int result = 0;
    if (str[0] != '-') {
        for (unsigned i = 0; i < strlen(str); ++i)
            result = result * 10 + (str[i] - 48);
    } else {
        for (unsigned i = 1; i < strlen(str); ++i)
            result = result * 10 + (str[i] - 48);
        result = result * -1;
    }

    return result;
}

int main() {
    char S[20]; scanf("%s", S);

    char S1[20] = {'\n'}, S2[20] = {'\n'};
    for (unsigned i = 0; i < strlen(S) - 2; ++i)
        S1[i] = S[i];
    S1[strlen(S1)] = S[strlen(S) - 1];
    for (unsigned i = 0; i < strlen(S) - 1; ++i)
        S2[i] = S[i];

    int one = char2int(S1);
    int two = char2int(S2);
    int thr = char2int(S);

    if (thr < two || thr < one) {
        if (one > two) printf("%d", one);
        else printf("%d", two);
    } else printf("%d", thr);

    printf("\n");

    return 0;
}
