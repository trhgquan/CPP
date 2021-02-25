/**
 * HDIVISR - https://codechef.com/FEB21C/problems/HDIVISR
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int n; cin >> n;
  for (int i = 10; i >= 1; --i)
    if (n % i == 0) {cout << i << '\n'; break;}

  return 0;
}
