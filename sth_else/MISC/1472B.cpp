/**
 * 1472B - https://codeforces.com/contest/1472/problem/B
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
    int s = 0;
    vector<int>a(n); for (auto& i : a) {cin >> i; s += i;}

    if (s % 2 != 0) cout << "NO" << endl;
    else if (n == 2 && a[0] == a[1]) cout << "YES" << endl;
    else {
      sort(a.begin(), a.end());
      int l = 0, can = 0;
      while (l < n - 1) {
        int currentSum = a[l];
        for (int r = l + 1; r < n; ++r) {
          if (currentSum + a[r] == s / 2) {can = 1; break;}
          currentSum += a[r];
        }
        if (can) break;
        ++l;
      }

      cout << (can ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
