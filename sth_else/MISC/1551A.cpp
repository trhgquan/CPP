/**
 * 1551A - https://codeforces.com/contest/1551/problem/A
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
    longint n; cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << ' ' << n / 3 << '\n';
    }
    else if (n % 3 == 1) {
      cout << n / 3 + 1 << ' ' << n / 3 << '\n';
    }
    else {
      cout << n / 3  << ' ' << n / 3 + 1 << '\n';
    }
  }

  return 0;
}
