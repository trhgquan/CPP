/**
 * 1476A - https://codeforces.com/contest/1476/problem/A
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
    longint n, k; cin >> n >> k;
    if (k % n == 0) cout << k / n << '\n';
    else if (n % k == 0) {
      cout << 1 << '\n';
    } else {
      if (n > k) {
        longint n0 = n;
        n = n - (n % k);
        cout << (n0 % n == 0 ? n0 / n : n0 / n + 1) << '\n';
      } else {
        cout << k / n + 1 << '\n';
      }
    }
  }

  return 0;
}
