/**
 * CODE - LINK
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string s; cin >> s;
    string res = "";
    for (int i = 0; i <= (int)s.size() - N; ++i) {
      int ones = 0;
      for (int j = 0; j < N; ++j)
        if (s[i + j] == '1') {ones = 1; break;}

      if (ones) res += '1';
      else res += '0';
    }

    cout << res << endl;
  }

  return 0;
}
