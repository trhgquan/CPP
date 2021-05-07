/**
 * 1520D - https://codeforces.com/contest/1520/problem/D
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    longint n; cin >> n;
    vector<longint>a(n); for (auto& it : a) cin >> it;

    map<longint, longint>count;
    for (int i = 0; i < n; ++i) {
      count[a[i] - i - 1]++;
    }

    longint res = 0;
    for (auto it : count) {
      res += (it.second * (it.second - 1)) / 2;
    }

    cout << res << '\n';
  }

  return 0;
}
