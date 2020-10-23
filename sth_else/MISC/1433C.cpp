/**
 * 1433C - https://codeforces.com/contest/1433/problem/C
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    set<longint>fishy;
    vector<longint>a(n); for (int i = 0; i < n; ++i) {cin >> a[i]; fishy.insert(a[i]);}
    if (fishy.size() == 1) cout << -1 << endl;
    else {
      longint thatFish = *prev(fishy.end());
      int res;
      for (int i = 0; i < n; ++i) {
        if (a[i] == thatFish && ((i > 0 && a[i - 1] < a[i]) || (i < n - 1 && a[i + 1] < a[i]))){
          res = i; break;
        }
      }
      cout << res + 1 << endl;
    }
  }

  return 0;
}
