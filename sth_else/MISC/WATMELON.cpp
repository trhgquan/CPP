/**
 * WATMELON - https://www.codechef.com/LTIME88B/problems/WATMELON
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int sum = 0;
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) {
      int u; cin >> u; sum += u;
    }

    cout << ((sum >= 0) ? "YES" : "NO") << endl;
  }

  return 0;
}
