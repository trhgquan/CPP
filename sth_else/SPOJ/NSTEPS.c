/**
 * NSTEPS - https://www.spoj.com/problems/NSTEPS
 * Code by @trhgquan - https://github.com/trhgquan
 * (using C for better performance).
 */
#include<stdio.h>

int main() {
    int n, u, v; scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &u, &v);
        if (u >= v) {
            if ((u == 0 || u == 1) && u == v)
                printf("%d\n", u);
            else if ((u % 2 == 0 && v % 2 == 0 && u - v == 2) ||
                    (u == v && u % 2 == 0))
                printf("%d\n", u + v);
            else if ((u % 2 != 0 && v % 2 != 0 && u - v == 2) ||
                    (u == v && u % 2 != 0))
                printf("%d\n", u + v - 1);
            else printf("No Number\n");
        } else printf("No Number\n");
    }
    return 0;
}
