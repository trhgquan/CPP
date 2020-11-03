/**
 * 1428A - https://codeforces.com/contest/1428/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--) {
    longint x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << ((x1 != x2 && y1 != y2) ? (abs(x1 - x2) + abs(y1 - y2) + 2) : (abs(x1 - x2) + abs(y1 - y2))) << endl;
  }

  return 0;
}
