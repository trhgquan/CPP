/**
 * PBKTRIA - https://codechef.com/COBN2021/problems/PBKTRIA
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
#define MOD 1000000007
using namespace std;

template<class T>
T quickPowWithMod(T x, T n, T mod) {
  if (n == 0) return 1;
  if (x == 0) return 0;

  T res;
  if (n % 2 == 0) {
    res = quickPowWithMod(x, n / 2, mod);
    res = (res * res) % mod;
  }
  else {
    res = x % mod;
    res = (res * quickPowWithMod(res, n - 1, mod) % mod) % mod;
  }

  return (T)((res + mod) % mod);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    longint n; cin >> n;
    longint total = n * 365 * 24 * 60 * 60;

    cout << quickPowWithMod((longint)2, total, (longint)MOD) << '\n';
  }

  return 0;
}
