/**
 * CDHNT1 - https://www.codechef.com/CHNT2021/problems/CDHNT1
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
    string s; cin >> s;
    int res = 0;
    for (char i : s) res += (i == '#');
    cout << res << '\n';
  }

  return 0;
}
