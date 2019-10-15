/**
 * Given integer n, output a prime which is nearest from n.
 * If two distances is equal, return the smallest of 2.
 */
#include <stdio.h>

int PRIME[2000004];

void generatePrimes() {
	for (int i = 2; i <= 2000004; ++i)
		PRIME[i] = 1;
	for (int i = 2; i <= 2000004; ++i)
		for (int j = 2; j * i <= 2000004; ++j)
			PRIME[i * j] = 0;
}

int nearestPrime(int n) {
	// Special case:
	if (n == 1) return 2;

    generatePrimes();

    int a, b;
    for (int i = n; i >= 2; --i)
		if (PRIME[i]) { a = i; break; }
	for (int i = n; i <= 2000004; ++i)
		if (PRIME[i]) { b = i; break; }

	if (n - a > b - n) return b;
	return a;
}

int main() {
	int n;

	FILE *fi = fopen("NEARPRIME.inp", "r+");
	FILE *fo = fopen("NEARPRIME.out", "w+");
	do {
		fscanf(fi, "%d", &n);
		if (n == 0) break;
		fprintf(fo, "%d\n", nearestPrime(n));
	} while (n != 0);
	return 0;
}
