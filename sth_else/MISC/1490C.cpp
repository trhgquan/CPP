/**
 * 1490C - https://codeforces.com/contest/1490/problem/C
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
    longint x; cin >> x; int can = 0;
    for (longint i = 1; x - i * i * i > 0; ++i) {
      longint y = x - i * i * i;
      longint z = cbrt(y);
      if (z * z * z == y) {
        can = 1; break;
      }
    }

    cout << (can ? "YES" : "NO") << '\n';
  }

  return 0;
}
