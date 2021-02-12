/**
 * SUMPOS - https://codechef.com/LTIME92C/problems/SUMPOS
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
    int x, y, z; cin >> x >> y >> z;
    cout << (((x + y == z) || (x + z == y) || (y + z == x)) ? "YES" : "NO") << '\n';
  }

  return 0;
}
