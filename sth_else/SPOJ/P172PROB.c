/**
 * P172PROB - https://www.spoj.com/PTIT/problems/P172PROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int n, k; scanf("%d%d", &n, &k);
    char string[n + 1]; scanf("%s", string);
    int tibberPos = 0; int cakePos = 0;

    for (int i = 0; i < n; ++i) {
        if (string[i] == 'G') tibberPos = i;
        if (string[i] == 'T') cakePos = i;
    }

    if (tibberPos == cakePos) printf("YES");
    else {
        int can = 1; int i;
        if (tibberPos > cakePos) {
            for (i = tibberPos; i > cakePos; i -= k)
                if (string[i] == '#') {can = 0; break;}
        } else {
            for (i = tibberPos; i < cakePos; i += k)
                if (string[i] == '#') {can = 0; break;}
        }
        if (can && i != cakePos) can = 0;
        if (can) printf("YES");
        else printf("NO");
    }
    return 0;
}
