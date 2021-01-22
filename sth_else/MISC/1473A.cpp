/**
 * 1473A - https://codeforces.com/contest/1473/problem/A
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
    int n, d; cin >> n >> d;
    vector<int>a(n); for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    int can = 1;
    for (int i : a) {if (i > d) {can = 0; break;}}
    if (!can) {
      for (int i = 0; i < n - 1; ++i) {
        if (a[i] + a[i + 1] <= d) {can = 1; break;}
      }
    }
    cout << (can ? "YES" : "NO") << endl;
  }

  return 0;
}
