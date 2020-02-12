/**
 * P145PROD - https://www.spoj.com/PTIT/problems/P145PROD
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

#define PIE 3.14159265358979

int main() {
    double R; scanf("%lf", &R);
    printf("%.6lf\n", R * R * PIE);
    printf("%.6lf", R * R * 2);
    return 0;
}
