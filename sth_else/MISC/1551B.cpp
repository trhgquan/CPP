/**
 * 1551B - https://codeforces.com/contest/1551/problem/B
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
    map<char, int> cnt;
    for (const char& c : s) cnt[c]++;
    int res = 0;
    int spare = 0;
    for (auto it : cnt) {
      if (it.second >= 2) ++res;
      else ++spare;
    }

    res += spare / 2;
    cout << res << '\n';
  }

  return 0;
}
