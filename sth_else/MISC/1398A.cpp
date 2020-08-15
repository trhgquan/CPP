/**
 * 1398A - https://codeforces.com/contest/1398/problem/A
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
    vector<int>A; for (int i = 1; i <= N; ++i) {int u; cin >> u; A.push_back(u);}

    bool can = true;
    int x, y, z;
    for (int i = 0; i < N - 2; ++i) {
      int sum = A[i] + A[i + 1];
      for (int j = i + 2; j < N; ++j) {
        if (sum <= A[j]) {
          x = i + 1;
          y = i + 2;
          z = j + 1;
          can = false;
          break;
        }
      }

      if (!can) break;
    }

    if (!can)
      cout << x << ' ' << y << ' ' << z << endl;
    else cout << -1 << endl;
  }

  return 0;
}
