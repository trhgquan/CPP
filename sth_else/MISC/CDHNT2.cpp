/**
 * CDHNT2 - https://www.codechef.com/CHNT2021/problems/CDHNT2
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
    vector<int>a(n); for(auto& it : a) cin >> it;

    sort(a.begin(), a.end());

    int x, y, z; z = INT_MAX;
    for (int i = 1; i < n; ++i) {
      if (abs(a[i] - a[i - 1]) < z) {
        x = a[i - 1];
        y = a[i];
        z = abs(a[i] - a[i - 1]);
      }
    }

    cout << x << ' ' << y << '\n';
  }

  return 0;
}
