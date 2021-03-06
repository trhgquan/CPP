/**
 * CDHNT4 - https://www.codechef.com/CHNT2021/problems/CDHNT4
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

vector<longint>precalc() {
  vector<longint>res(21, 1);
  for (int i = 1; i <= 20; ++i) res[i] = res[i - 1] * i;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  vector<longint>p = precalc();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << p[n] << '\n';
  }

  return 0;
}
