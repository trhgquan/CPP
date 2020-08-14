/**
 * P131SUMC - https://www.spoj.com/PTIT/problems/P131SUMC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    double a, b, c, d; scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double max = fabs(a/c - b/d); int rotate = 0;
    if (fabs(c/d - a/b) > max) {max = fabs(c/d - a/b); rotate = 1;}
    if (fabs(d/b - c/a) > max) {max = fabs(d/b - c/a); rotate = 2;}
    if (fabs(b/a - d/c) > max) {rotate = 3;}
    printf("%d", rotate);
    return 0;
}
