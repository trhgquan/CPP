/**
 * EVENGAME - https://codechef.com/LTIME92C/problems/EVENGAME
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
    longint s = 0;
    for (int i = 0; i < n; ++i) {
      longint u; cin >> u; s += u;
    }

    cout << (s % 2) + 1 << '\n';
  }

  return 0;
}
