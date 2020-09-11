/**
 * 1397A - https://codeforces.com/problemset/problem/1397/A
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
    map<char, int>count;
    for (int i = 1; i <= N; ++i) {
      string s; cin >> s;
      for (char j : s) ++count[j];
    }

    bool can = true;
    for (map<char, int>::iterator it = count.begin(); it != count.end(); ++it)
      if (it->second % N != 0) {can = false; break;}

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
