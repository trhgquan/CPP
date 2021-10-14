/**
 * P201PROJ - https://www.spoj.com/PTIT/problems/P201PROJ
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int count(longint x) {
  longint current = 9;
  int res = 0;
  while (x >= current) {
    ++res;
    current = current * 10 + 9;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    longint A, B; cin >> A >> B;
    cout << A * count(B) << endl;
  }

  return 0;
}
