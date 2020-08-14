/**
 * P165PROH - https://www.spoj.com/PTIT/problems/P165PROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<stdio.h>
#include<math.h>

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int X, Y, Z, a, b, c; scanf("%d%d%d", &X, &Y, &Z);
		c = sqrt(Y * Z / X); a = Y / c; b = Z / c;
		printf("%d\n", 4 * (a + b + c));
	}
	return 0;
}
