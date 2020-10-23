/**
 * 1433E - https://codeforces.com/contest/1433/problem/E
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // Solution goes here.
  longint n; cin >> n;
  longint res = 1;
  for (longint i = 1; i < n; ++i) res *= i;
  cout << res / (n / 2) << endl;

  return 0;
}
