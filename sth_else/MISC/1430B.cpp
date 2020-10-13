/**
 * 1430B - https://codeforces.com/contest/1430/problem/B
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  // freopen("test.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  ll t; cin >> t;
  while (t--) {
    ll n, k; cin >> n >> k;
    vector<ll>a; for (ll i = 1; i <= n; ++i) {ll u; cin >> u; a.push_back(u);}

    sort(a.begin(), a.end(), greater<ll>());
    ll currentSum = *a.begin();
    for (ll i = 1; i <= k; ++i) currentSum += a[i];

    cout << currentSum << endl;
  }

  return 0;
}
