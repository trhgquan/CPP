/**
 * 1417A - https://codeforces.com/contest/1417/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int n, k; cin >> n >> k;
    vector<int>a; for (int i = 1; i <= n; ++i) {int u; cin >> u; a.push_back(u);}

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = a.size() - 1; i > 0; --i) res += (k - a[i]) / a[0];

    cout << res << endl;
  }

  return 0;
}
