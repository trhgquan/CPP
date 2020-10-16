/**
 * 1424G - https://codeforces.com/contest/1424/problem/G
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  // freopen("test.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  map<int, int>years;
  for (int i = 1; i <= n; ++i) {
    int b, d; cin >> b >> d;
    ++years[b]; --years[d];
  }

  int count = 0; int bestCount = 0; pair<int, int>bestinterval;
  for (auto it = years.begin(); it != years.end(); ++it) {
    count += it->second;
    if (count > bestCount) {
      bestCount = count;
      bestinterval = {it->first, bestCount};
    }
  }

  cout << bestinterval.first << ' ' << bestinterval.second;

  return 0;
}
