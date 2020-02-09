/**
 * BCTEST11 - https://www.spoj.com/PTIT/problems/BCTEST11
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    int can_divide[30] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4777, 7444, 7447, 7477, 7777};
    int N; scanf("%d", &N);
    int can = 0;
    for (int i = 0; i < 24; ++i)
        if (N % can_divide[i] == 0) {can = 1; break;}
    if (can) printf("YES\n");
    else printf("NO\n");
    return 0;
}
