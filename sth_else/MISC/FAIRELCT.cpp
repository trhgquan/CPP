/**
 * FAIRELCT - https://www.codechef.com/JAN21C/problems/FAIRELCT
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
    int n, m; cin >> n >> m;
    vector<int>a(n, 0), b(m, 0);
    int sA, sB; sA = sB = 0;
    for (int i = 0; i < n; ++i) {cin >> a[i]; sA += a[i];}
    for (int i = 0; i < m; ++i) {cin >> b[i]; sB += b[i];}
    sort(a.begin(), a.end()); sort(b.begin(), b.end(), greater<int>());

    int res = 0;
    for (int i = 0; i < min(n, m); ++i) {
      if (sA > sB) break;
      sA -= a[i]; sA += b[i];
      sB -= b[i]; sB += a[i];
      ++res;
    }

    cout << ((sA > sB) ? res : -1) << endl;
  }

  return 0;
}
