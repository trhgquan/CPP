/*
 * https://www.spoj.com/PTIT/problems/P166PROH/
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include <stdio.h>

int PRIME[4000];

// Because maximum n is 3000, so prime list limit is bigger than 3000.
void generatePrimes() {
	PRIME[1] = 0;
	for (int i = 2; i <= 4000; ++i) PRIME[i] = 1;
	for (int i = 2; i <= 4000; ++i)
		for (int j = 2; i * j <= 4000; ++j)
			if (PRIME[i * j]) PRIME[i * j] = 0;
}

int main() {
	int n;
	generatePrimes();
	scanf("%d", &n);

	int count = 0;

	for (int i = 2; i <= n; ++i) {
		int can_divide = 0;
		for (int j = 2; j < i; ++j)
			if (PRIME[j] && i % j == 0) can_divide++;
		if (can_divide == 2) count++;
	}

	printf("%d\n", count);
	return 0;
}
