/**
 * BILLRD - https://www.codechef.com/JAN21C/problems/BILLRD
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
    int n, k, x, y; cin >> n >> k >> x >> y;

    if (x == y) cout << n << ' ' << n << endl;
    else {
      int b = y - x;
      vector<pair<int, int>>collapse;
      if (b > 0) {
        collapse.push_back({n - b, n});
        collapse.push_back({n, n - b});
        collapse.push_back({b, 0});
        collapse.push_back({0, b});
      }
      else {
        collapse.push_back({n, n + b});
        collapse.push_back({n + b, n});
        collapse.push_back({0, -b});
        collapse.push_back({-b, 0});
      }

      pair<int, int>res = collapse[(k - 1) % 4];
      cout << res.first << ' ' << res.second << endl;
    }
  }

  return 0;
}
