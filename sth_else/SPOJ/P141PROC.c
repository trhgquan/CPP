/**
 * P141PROC - https://www.spoj.com/PTIT/problems/P141PROC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    int R = 0;
    while (N--) {
        char S[5]; scanf("%s", S);
        if (S[0] == '+' || S[2] == '+') ++R;
        else --R;
    }
    printf("%d", R);
    return 0;
}
