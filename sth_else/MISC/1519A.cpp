/**
 * 1519A - https://codeforces.com/contest/1519/problem/A
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
    longint r, b, d; cin >> r >> b >> d;
    longint y = min(r, b);
    longint x = max(r, b);
    while (y > 0) {
      x -= d + 1;
      --y;
    }

    cout << ((x <= 0) && (y <= 0) ? "YES" : "NO") << endl;
  }

  return 0;
}
