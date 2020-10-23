/**
 * 1433A - https://codeforces.com/contest/1433/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // Solution goes here.
  vector<pair<int, int>>sieve;
  for (int i = 1; i <= 9; ++i) {
    int length = 1;
    int ins = 0;
    while (length <= 4) {
      sieve.push_back({ins * 10 + i, length});
      ins = ins * 10 + i; ++length;
    }
  }

  int t; cin >> t;
  while (t--) {
    int x; cin >> x;

    int res = 0;
    for (auto it : sieve) {
      res += it.second;
      if (it.first == x) break;
    }

    cout << res << endl;
  }

  return 0;
}
