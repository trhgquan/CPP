/**
 * 1519B - https://codeforces.com/contest/1519/problem/B
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
    longint n, m, k; cin >> n >> m >> k;
    longint a = (n - 1) + n * (m - 1);
    cout << (a == k ? "YES" : "NO") << endl;
  }

  return 0;
}
