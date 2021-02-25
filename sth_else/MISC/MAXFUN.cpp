/**
 * MAXFUN - https://codechef.com/FEB21C/problems/MAXFUN
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
    vector<longint>a(n); for(auto& it : a) cin >> it;

    sort(a.begin(), a.end());

    cout << (abs(a[0] - a[1]) + abs(a[1] - a[n - 1]) + abs(a[0] - a[n - 1])) << '\n';
  }

  return 0;
}
