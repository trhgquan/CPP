/**
 * SK_001 - https://www.spoj.com/problems/SK001
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
#define MOD 1000000007
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    longint n; cin >> n;
    vector<longint> a(n); for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());
    vector<longint> b(n, 1), c(n, 1);
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) b[i] = b[i - 1];
      else b[i] = b[i - 1] + 1;

      c[i] = (c[i - 1] + b[i]) % MOD;
    }

    cout << c[n - 1] << '\n';
  }

  return 0;
}
