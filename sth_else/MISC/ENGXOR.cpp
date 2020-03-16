/**
 * ENGXOR - https://www.codechef.com/MARCH20B/problems/ENGXOR
 * Codechef March Long Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int isEven(int a) {
    int count = 0;
    while (a > 0) {
        count += a % 2;
        a /= 2;
    }
    return (count % 2 == 0);
}

int main() {
    // Solution goes here
    int T; scanf("%d", &T);
    while (T--) {
        int N, Q; scanf("%d%d", &N, &Q);
        int even = 0; int odds = 0;
        for (int i = 1; i <= N; ++i) {
            int u; scanf("%d", &u);
            if (isEven(u)) ++even;
            else ++odds;
        }
        while (Q--) {
            int P; scanf("%d", &P);
            if (isEven(P)) printf("%d %d", even, odds);
            else printf("%d %d", odds, even);
            printf("\n");
        }
    }
    return 0;
}
