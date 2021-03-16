/**
 * MTEVTSK2 - https://codechef.com/COBN2021/problems/MTEVTSK2
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
    vector<int>a(n); for(auto& it : a) cin >> it;
    vector<int>sum = a;

    int res = -1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (a[j] < a[i]) {
          sum[i] = max(sum[i], a[i] + sum[j]);
          res = max(res, sum[i]);
        }
      }
    }

    cout << res << '\n';
  }

  return 0;
}
