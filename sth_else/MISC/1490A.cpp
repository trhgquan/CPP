/**
 * 1490A - https://codeforces.com/contest/1490/problem/A
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

    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
      if ((double)(max(a[i], a[i + 1]) * 1.0 / min(a[i], a[i + 1]) * 1.0) > 2.0) {
        int current = min(a[i], a[i + 1]);
        int destination = max(a[i], a[i + 1]);
        int diff = 0;
        while (current * 2 < destination) {
          current *= 2; ++diff;
        }
        res += diff;
      }
    }

    cout << res << '\n';
  }

  return 0;
}
