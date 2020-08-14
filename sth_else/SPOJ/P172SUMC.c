/**
 * P172SUMC - https://www.spoj.com/PTIT/problems/P172SUMC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    if (N == 0) printf("1");
    else {
        while (N > 4) N -= 4;
        if (N == 4) printf("6");
        if (N == 3) printf("2");
        if (N == 2) printf("4");
        if (N == 1) printf("8");
    }
    return 0;
}
