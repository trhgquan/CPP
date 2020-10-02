/**
 * 1408A - https://codeforces.com/contest/1408/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  // freopen("test.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int board[4][101];
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= n; ++j)
        cin >> board[i][j];
    }

    vector<int>res;
    res.push_back(-1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 3; ++j){
        if (board[j][i] != res[i % n + 1] && board[j][i] != res[i - 1]) {
          res.push_back(board[j][i]);
          break;
        }
      }
    }

    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
    cout << endl;
  }

  return 0;
}
