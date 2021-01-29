/**
 * 1475A - https://codeforces.com/contest/1475/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

void solveNaive() {
  int t; cin >> t;
  while (t--) {
    longint n; cin >> n;
    while (n > 1 && n % 2 == 0) n /= 2;
    cout << ((n == 1) ? "NO" : "YES") << '\n';
  }
}

void solveObservation() {
  int t; cin >> t;
  while (t--) {
    longint n; cin >> n;
    cout << ((n & (n - 1)) ? "YES" : "NO") << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  solveNaive();
  // solveObservation();

  return 0;
}
