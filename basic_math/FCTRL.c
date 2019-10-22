/**
 * https://www.purplemath.com/modules/factzero.htm
 * Code by @trhgquan - Greedy approach
 * Problem original: FCTRL - Factorial (SPOJ)
 */
#include <stdio.h>

int main() {
    int T;
    int n, count;
    scanf("%d", &T);
    while (T--) {
        count = 0;
        scanf("%d", &n);
        while (n >= 5) {
            count += n / 5;
            n /= 5;
        }
        printf("%d\n", count);
    }
    return 0;
}
