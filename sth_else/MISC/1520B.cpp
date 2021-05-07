/**
 * 1520B - https://codeforces.com/contest/1520/problem/B
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

longint buildNumber(int max) {
  stringstream builder;

  int current = 0;
  while (current < max) {
    builder << 1;
    ++current;
  }

  return stoi(builder.str());
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    longint n; cin >> n;
    int res = 0;
    for (int i = 1; i <= 9; ++i) {
      longint currentNum = buildNumber(i);

      for (int j = 1; j <= 9; ++j) {
        longint current = currentNum * j;
        if (current <= n) ++res;
        else break;
      }

      if (currentNum > n) break;
    }

    cout << res << '\n';
  }

  return 0;
}
