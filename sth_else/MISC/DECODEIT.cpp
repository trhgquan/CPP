/**
 * DECODEIT - https://www.codechef.com/JAN21C/problems/DECODEIT
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
    for (int i = 0; i < n - 3; i += 4) {
      int l = 0; int r = 15;

      for (int j = 0; j <= 2; ++j) {
        if (s[j + i] == '1') l = ceil((l + r) * 1.0 / 2.0);
        else r = (l + r) / 2;
      }

      int res = (s[i + 3] == '1' ? r : l);
      cout << (char)(res + 'a');
    }
    cout << endl;
  }

  return 0;
}
