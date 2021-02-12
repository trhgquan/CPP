/**
 * INTRVS - https://codechef.com/LTIME92C/problems/INTRVS
 * Codechef January Lunchtime Division C - 2021.
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
    int n, k; cin >> n >> k;
    vector<int>a(n); for(auto& it : a) cin >> it;

    int wa = 0;
    int tle = 0;
    int bot = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) ++wa;
      else if (a[i] > k) ++tle;
      else if (a[i] <= 1) ++bot;
    }

    if (n - wa < ceil(n * 1.0 / 2.0)) cout << "Rejected" << '\n';
    else if (tle >= 1) cout << "Too Slow" << '\n';
    else if (bot == n) cout << "Bot" << '\n';
    else cout << "Accepted" << '\n';
  }

  return 0;
}
