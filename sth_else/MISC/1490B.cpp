/**
 * 1490B - http://codeforces.com/contest/1490/problem/B
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
    vector<int>a(n); for (auto& it : a) cin >> it;
    int c[3] = {0}; int res = 0;
    for (int i = 0; i < n; ++i) c[a[i] % 3]++;
    while (c[0] != c[1] || c[1] != c[2]) {
      if (c[2] > c[0]) {
        --c[2]; ++c[0];
      }

      else if (c[1] > c[2]) {
        ++c[2]; --c[1];
      }

      else if (c[0] > c[1]) {
        --c[0]; ++c[1];
      }

      ++res;
    }
    cout << res << '\n';
  }

  return 0;
}
