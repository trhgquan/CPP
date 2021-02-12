/**
 * BINSUBS - https://codechef.com/LTIME92C/problems/BINSUBS
 * Codechef January Lunchtime Division C - 2021.
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
    string s; cin >> s;
    int res = 0;

    stack<char>stk;
    for (char i : s) {
      if (stk.empty()) stk.push(i);
      else {
        if (stk.top() == '1' && i == '0') {
          ++res;
          stk.pop();
        } else stk.push(i);
      }
    }

    cout << res << '\n';
  }

  return 0;
}
