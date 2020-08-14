/**
 * P162PROG - https://www.spoj.com/PTIT/problems/P162PROG
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x; cin >> x;
	bitset<32>virus(x);
	cout << virus.count();
	return 0;
}
