/**
 * P178PROF - https://www.spoj.com/PTIT/problems/P178PROF
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N;
    while (scanf("%d", &N)) {
        if (N == 0) break;

        int count = 0;
        while (N != 1) {
            if (N % 2 == 0) N /= 2;
            else N = N * 3 + 1;
            ++count;
        }
        printf("%d\n", count + 1);
    }
    return 0;
}
