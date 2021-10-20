/**
 * P204PROD - https://www.spoj.com/PTIT/problems/P204PROD
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
    vector<int>a(n); for(auto& i : a) cin >> i;

    int odds, even; odds = even = 0;
    for (int i : a) {
      if (!(i & 1)) ++even;
      else ++odds;
    }

    if (even == n) cout << "NO";
    else if ((odds == n) && !(n & 1)) cout << "NO";
    else cout << "YES";
    cout << '\n';
  }

  return 0;
}
