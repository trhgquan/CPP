/**
 * P145SUMF - https://www.spoj.com/PTIT/problems/P145SUMF
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int R, C, A, B; cin >> R >> C >> A >> B;
	vector<string>g;
	string bs = "";
	string ws = "";
	for (int i = 1; i <= C ; ++i) {
		for (int j = 1; j <= B; ++j) {
			if (i % 2 == 0) {
				bs += 'X';
				ws += '.';
			} else {
				bs += '.';
				ws += 'X';
			}
		}
	}
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= A; ++j) {
			if (i % 2 == 0) g.push_back(bs);
			else g.push_back(ws);
		}
	}

	for (unsigned i = 0; i < g.size(); ++i)
		cout << g[i] << endl;
	return 0;
}
