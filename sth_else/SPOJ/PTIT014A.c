/**
 * PTIT014A - https://www.spoj.com/PTIT/problems/PTIT014A
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char ans[11];
        scanf("%s", ans);
        if (ans[0] == 'h') {++T; continue;}
        else {
            if (ans[0] == 'd') printf("2\n");
            else if (ans[0] == 'l') printf("1\n");
            else printf("3\n");
        }
    }
    return 0;
}
