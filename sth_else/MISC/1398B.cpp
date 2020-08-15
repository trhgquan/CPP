/**
 * 1398B - https://codeforces.com/contest/1398/problem/B
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
    vector<int>optimal;
    int count = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '1') ++count;
      else {
        if (count != 0) {
          optimal.push_back(count);
          count = 0;
        }
      }
    }

    if (count != 0) optimal.push_back(count);

    if (optimal.size() == 0) cout << 0 << endl;
    else {
      sort(optimal.begin(), optimal.end());

      int res = 0;
      count = 0;
      for (int i = optimal.size() - 1; i >= 0; --i) {
        if (count % 2 == 0) res += optimal[i];
        ++count;
      }

      cout << res << endl;
    }
  }

  return 0;
}
