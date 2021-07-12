/**
 * 1547A - https://codeforces.com/contest/1547/problem/A
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
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;

    if (xa == xf && xf == xb && ((ya >= yf && yf >= yb) || (ya <= yf && yf <= yb))) {
      cout << abs(xa - xb) + abs(ya - yb) + 2;
    }
    else if (ya == yf && yf == yb && ((xa >= xf && xf >= xb) || (xa <= xf && xf <= xb))) {
      cout << abs(xa - xb) + abs(ya - yb) + 2;
    }
    else {
      cout << abs(xa - xb) + abs(ya - yb);
    }
    cout << '\n';
  }

  return 0;
}
