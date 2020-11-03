/**
 * 1367A - https://codeforces.com/contest/1367/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    string s; cin >> s;
    string res = ""; res += s[0];

    for (int i = 1; i < (int)s.size(); i += 2)
      res += s[i];

    cout << res << endl;
  }

  return 0;
}
