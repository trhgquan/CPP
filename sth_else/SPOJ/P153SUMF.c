/**
 * P153SUMF - https://www.spoj.com/PTIT/problems/P153SUMF
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    int alphabet[27] = {0};
    for (int i = 0; i <= N; ++i) {
        char a; scanf("%c", &a);
        if (a >= 'a' && a <= 'z') a = a - 32;
        ++alphabet[a - 65 + 1];
    }

    int can = 1;
    for (int i = 1; i <= 26; ++i)
        if (!alphabet[i]) {can = 0; break;}
    if (can) printf("YES");
    else printf("NO");
    return 0;
}
