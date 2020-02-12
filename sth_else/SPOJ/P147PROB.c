/**
 * P147PROB - https://www.spoj.com/PTIT/problems/P147PROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>

int main() {
    double T; scanf("%lf", &T);
    double V = 0;
    for (int i = 1; i <= T; ++i) {double P; scanf("%lf", &P); V += P;}
    printf("%.12lf", V / T);
    return 0;
}
