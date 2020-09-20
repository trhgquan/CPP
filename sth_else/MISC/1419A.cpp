/**
 * 1419A - https://codeforces.com/contest/1419/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string number; cin >> number;
    int res = 0;
    // Ryze move last move, so the last position is even.
    if (N % 2 == 0) {
      for (int i = 1; i <= N; ++i)
        if ((i % 2 == 0) && (number[i - 1] - '0') % 2 == 0) {res = 1; break;}

      // At here, res = 1 means Brench won/
      cout << ((res) ? 2 : 1) << endl;
    }

    // Brench move last move.
    else {
      for (int i = 1; i <= N; ++i)
        if ((i % 2 != 0) && (number[i - 1] - '0') % 2 != 0) {res = 1; break;}

      // At here, res = 1 means Ryze won.
      cout << ((res) ? 1 : 2) << endl;
    }
  }

  return 0;
}
