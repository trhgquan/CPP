#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 12

// pwr[d][n] is d^n
long long pwr[10][MAX_DIGITS + 1];

// Digits and final index of number being considered.
int digits[MAX_DIGITS];
int m;

FILE *f;

// Fill pwr.
void fill_tbls(void)
{
	for (int d = 0; d < 10; d++) {
		pwr[d][0] = 1;
		for (int p = 1; p <= MAX_DIGITS; p++)
			pwr[d][p] = pwr[d][p-1] * d;
	}
}

// qsort comparison for integers descending
int cmp_ints_desc(const void *vpa, const void *vpb)
{
	const int *pa = vpa, *pb = vpb;
	return *pb - *pa;
}

// Test current number and print if narcissistic.
void test(void)
{
	long long sum = 0;
	for (int i = 0; i <= m; i++)
		sum += pwr[digits[i]][m + 1];
	int sum_digits[MAX_DIGITS * 2];
	int n = 0;
	for (long long s = sum; s; s /= 10)
		sum_digits[n++] = s % 10;
	if (n == m + 1) {
		qsort(sum_digits, n, sizeof(int), cmp_ints_desc);
		if (memcmp(sum_digits, digits, n * sizeof(int)) == 0)
			fprintf(f, "%lld\n", sum);
	}
}

// Recursive generator of non-increasing digit strings.
// Calls test when a string is complete.
void gen(int i, int min, int max)
{
	if (i > m)
		test();
	else {
		for (int d = min; d <= max; d++) {
			digits[i] = d;
			gen(i + 1, 0, d);
		}
	}
}

// Fill tables and generate.
int main(void)
{
	f = fopen("nar.txt", "w+");
	fill_tbls();
	for (m = 0; m < MAX_DIGITS; m++)
		gen(0, 1, 9);
	return 0;
}
