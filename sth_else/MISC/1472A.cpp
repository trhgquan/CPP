/**
 * 1472A - https://codeforces.com/contest/1472/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  longint t; cin >> t;
  while (t--) {
    longint w, h, n; cin >> w >> h >> n;
    longint res = 1;
    while (w % 2 == 0 && w > 0) {res *= 2; w /= 2;}
    while (h % 2 == 0 && h > 0) {res *= 2; h /= 2;}

    cout << ((res < n) ? "NO" : "YES") << endl;
  }

  return 0;
}
