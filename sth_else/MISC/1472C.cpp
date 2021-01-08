/**
 * 1472C - https://codeforces.com/contest/1472/problem/C
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
    int n; cin >> n;
    longint res = -1;
    vector<longint>a(n); for(auto& i : a) cin >> i;
    vector<longint>b = a;
    for (int i = 0; i < n; ++i) {
      if (i + a[i] < n) b[i + a[i]] = max(a[i + a[i]] + b[i], b[i + a[i]]);
      res = max(res, b[i]);
    }

    cout << res << endl;
  }

  return 0;
}
