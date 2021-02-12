/**
 * EVENDIFF - https://codechef.com/LTIME92C/problems/EVENDIFF
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
    int n; cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      int u; cin >> u;
      if (u % 2 == 0) ++a; else ++b;
    }

    cout << min(a, b) << endl;
  }

  return 0;
}
