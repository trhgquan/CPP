/**
 * TEAMNAME - https://codechef.com/FEB21C/problems/TEAMNAME
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
    map<string, set<char>>funny;
    for (int i = 1; i <= n; ++i) {
      string s; cin >> s;
      char prefix = s[0]; s.erase(0, 1);
      funny[s].insert(prefix);
    }

    int res = 0;

    for (map<string, set<char>>::iterator current = funny.begin(); current != prev(funny.end()); ++current) {
      for (map<string, set<char>>::iterator nextElement = next(current); nextElement != funny.end(); ++nextElement) {
        int invalid = 0;
        for (auto c : current->second)
          if (nextElement->second.find(c) != nextElement->second.end())
            ++invalid;

        int calculation = (current->second.size() - invalid) * (nextElement->second.size() - invalid);

        res += calculation;
      }
    }

    cout << res * 2 << '\n';
  }

  return 0;
}
