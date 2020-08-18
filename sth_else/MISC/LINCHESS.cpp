/**
 * LINCHESS - https://www.codechef.com/AUG20B/problems/LINCHESS
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  ll T; cin >> T;
  while (T--) {
    ll N, K; cin >> N >> K;
    map<ll, ll>canEat;

    for (int i = 1; i <= N; ++i) {
      ll u; cin >> u;
      if (u <= K && K % u == 0) canEat.insert({u, 1});
    }

    if (canEat.size() == 0) cout << -1 << endl;
    else cout << prev(canEat.end())->first << endl;
  }

  return 0;
}
