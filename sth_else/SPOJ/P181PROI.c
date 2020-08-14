/**
 * P181PROI - https://www.spoj.com/PTIT/problems/P181PROI
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    char code[101]; scanf("%s", code);
    int res = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (code[i - 1] == '0' && code[i] == '1' && code[i + 1] == '0') {
            ++res; code[i + 1] = '1';
        }
    }
    printf("%d", res);
    return 0;
}
