/**
 * PTIT124H - https://www.spoj.com/PTIT/problems/PTIT124H
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    long a, b, c, d, e, f; scanf("%ld%ld%ld%ld%ld%ld", &a, &b, &c, &d, &e, &f);
    if (a == c) printf("%ld", e);
    else if (a == e) printf("%ld", c);
    else printf("%ld", a);
    printf(" ");
    if (b == d) printf("%ld", f);
    else if (b == f) printf("%ld", d);
    else printf("%ld", b);
    return 0;
}
