/**
 * 1512A - https://codeforces.com/contest/1512/problem/A
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
    vector<int>a(n); for (auto& it : a) cin >> it;
    int currentIndex = -1;

    for (int i = 1; i < n - 1; ++i) {
      if (a[i] != a[i + 1] && a[i] != a[i - 1]) {currentIndex = i; break;}
    }

    if (currentIndex == -1) {
      if (a[0] != a[1] && a[1] == a[2]) currentIndex = 0;
    }

    if (currentIndex == -1) {
      if (a[n - 1] != a[n - 2] && a[n - 2] == a[n - 3]) currentIndex = n - 1;
    }

    cout << (currentIndex + 1) << '\n';
  }

  return 0;
}
