/**
 * P195SUMC - https://www.spoj.com/PTIT/problems/P195SUMC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int N; scanf("%d", &N);
    int can = 1;
    int cash[3] = {0};
    for (int i = 1; i <= N; ++i) {
        int c; scanf("%d", &c);
        // If the customer give u a 25$,  u will have a 25$ in cash[0]
        if (c == 25) ++cash[0];
        else if (c == 50) {
            // If the customer give u a 50$, you must return him 25$ in cash[0] and u will have a 50$ in cash[1]
            if (cash[0] > 0) {--cash[0];++cash[1];}
            else {can = 0; break;}
        }
        else {
            // If the customer give u a 50$, you must return him total 75$
            // That will be 25$ in cash[0] and 50$ in cash[1]. After that, u will have a 100$ in cash[2]
            if (cash[0] >= 1 && cash[1] >= 1) {--cash[0]; ++cash[1]; ++cash[2];}
            else {can = 0; break;}
        }
    }
    if (!can) printf("NO\n");
    else printf("YES\n");
    return 0;
}
