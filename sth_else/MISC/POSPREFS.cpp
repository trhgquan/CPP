/**
 * POSPREFS - https://codechef.com/DEC20B/problems/POSPREFS
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--) {
    int k, n; cin >> n >> k;

    k = n - k;

    vector<int>a; for (int i = 0; i < n; ++i) a.push_back(i + 1);

    int count = 0;
    for (int i = 1; i < n && count < k; i += 2) {
      a[i] *= -1; ++count;
    }

    int i = ((a[n - 1] < 0) ? n - 2 : n - 1);

    for (; i >= 0 && count < k; i -= 2) {
      a[i] *= -1; ++count;
    }

    for (int i : a) cout << i << ' ';
    cout << endl;
  }

  return 0;
}
