/*
 * https://www.spoj.com/problems/NUB04/
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include <iostream>

#define lli long long int

bool isPrime(lli a) {
	if (a == 0 || a == 1) return false;
	if (a == 2) return true;

	for (lli i = 2; i * i <= a; ++i)
		if (a % i == 0) return false;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	lli i;
	while (std::cin >> i) {
		if (isPrime(i)) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
	return 0;
}
