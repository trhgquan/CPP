/**
 * TOTSCR - https://www.codechef.com/CCRC21B/problems/TOTSCR
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
    vector<longint>a(k); for (auto& it : a) cin >> it;
    vector<longint>points(n, 0);
    for (int i = 0; i < n; ++i) {
      string s; cin >> s;
      for (int j = 0; j < k; ++j) {
        points[i] += (s[j] == '1') ? a[j] : 0;
      }
    }
    for (int i = 0; i < n; ++i) cout << points[i] << '\n';
  }

  return 0;
}
