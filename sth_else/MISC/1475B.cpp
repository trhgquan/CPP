/**
 * 1475B - https://codeforces.com/contest/1475/problem/B
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
    int can = 0;
    for (int i = 0; n - 2021 * i >= 0; ++i)
      if ((n - 2021 * i) % 2020 == 0) {can = 1; break;}

    cout << ((can) ? "YES" : "NO") << '\n';
  }

  return 0;
}
