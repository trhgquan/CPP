/**
 * P135SUME - https://www.spoj.com/PTIT/problems/P135SUME
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int count = 0; int prev = 0;
    for (int i = 1; i <= 8; ++i) {
        int now; scanf("%d", &now);
        if (now > prev) ++count;
        else --count;
        prev = now;
    }
    if (count == 8) printf("ascending");
    else if (count == -6) printf("descending");
    else printf("mixed");
    return 0;
}
