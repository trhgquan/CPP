/**
 * 1433B - https://codeforces.com/contest/1433/problem/B
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int>a(n); for (int i = 0; i < n; ++i) cin >> a[i];

    int l, r, res; res = l = r = 0;
    while (r < n) {
      if (a[l] == 1 && a[r] == 1 && l != r) {
        res += r - l - 1;
        l = r;
      } else if (a[r] == 1 && a[l] != 1) {
        l = r;
      }
      ++r;
    }

    cout << res << endl;
  }

  return 0;
}
