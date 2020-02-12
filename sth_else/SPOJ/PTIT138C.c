/**
 * PTIT138C - https://www.spoj.com/PTIT/problems/PTIT138C
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<string.h>

char toUppercase(char A) {
    if (A >= 'a' && A <= 'z') return A - 32;
    return A;
}

int charToInt(char A) {
    A = toUppercase(A);
    if (A >= 'A' && A <= 'C') return 2;
    if (A >= 'D' && A <= 'F') return 3;
    if (A >= 'G' && A <= 'I') return 4;
    if (A >= 'J' && A <= 'L') return 5;
    if (A >= 'M' && A <= 'O') return 6;
    if (A >= 'P' && A <= 'S') return 7;
    if (A >= 'T' && A <= 'V') return 8;
    return 9;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while (T--) {
        char S[51]; scanf("%s", S);
        int count[51];
        // Number from text
        for (unsigned i = 0; i < strlen(S); ++i)
            count[i] = charToInt(S[i]);

        int can = 1;
        for (unsigned i = 0; i < strlen(S) / 2; ++i) {
            if (count[i] != count[strlen(S) - i - 1]) {can = 0; break;}
        }

        if (can) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
