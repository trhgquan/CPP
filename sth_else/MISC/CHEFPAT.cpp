/**
 * CHEFPAT - https://www.codechef.com/CCRC21C/problems/CHEFPAT
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
    vector<pair<int, int>>a;
    vector<int>b(n);
    for (int i = 0; i < n; ++i) {
      int u; cin >> u;
      a.push_back({u, i});
    }

    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
      return (x.first > y.first) || (x.first == y.first && x.second < y.second);
    });

    for (int i = 0; i < n; ++i) {
      b[a[i].second] = i + 1;
    }

    for (int i = 0; i < n; ++i) cout << b[i] << ' ';
    cout << '\n';
  }

  return 0;
}
