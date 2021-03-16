/**
 * CSNUM - https://www.codechef.com/COBN2021/problems/CSNUM
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
    int count = 0, sum = 0;
    while (n > 0) {
      ++count;
      sum += n % 10; n /= 10;
    }

    cout << (!(sum % count) ? "Good Work" : "Try Again") << '\n';
  }

  return 0;
}
