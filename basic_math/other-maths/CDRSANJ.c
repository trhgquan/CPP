#include <stdio.h>

int f(int x) {
	if (x == 0 || x == 1 || x == 2)
		return x;

	int ret = 0;

	while (x % 2 == 0) {
		ret += 2;
		x /= 2;
	}

	return ret;
}

int main() {
	int x;
	scanf("%d", &x);
	printf("%d\n", f(x));
	return 0;
}
