/**
 * CDHNT5 - https://www.codechef.com/CHNT2021/problems/CDHNT5
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int n; cin >> n;
  map<int, int>zoo;
  while (n--) {
    int id; cin >> id; ++zoo[id];
  }

  int res = zoo.begin()->first;
  int m = zoo.begin()->second;
  for (auto it = next(zoo.begin()); it != zoo.end(); ++it) {
    if (it->second > m) {
      m = it->second;
      res = it->first;
    }
  }

  cout << res << '\n';

  return 0;
}
