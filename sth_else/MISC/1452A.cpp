/**
 * 1452A - https://codeforces.com/contest/1452/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  // freopen("test.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    int med = abs(x - y);

    if (med <= 1) cout << x + y << endl;
    else cout << 2 * min(x, y) + (2 * abs(x - y) - 1) << endl;
  }

  return 0;
}
