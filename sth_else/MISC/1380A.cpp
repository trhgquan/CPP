/**
 * 1380A - https://codeforces.com/contest/1380/problem/A
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
    vector<int>P; for (int i = 1; i <= N; ++i) {int u; cin >> u; P.push_back(u);}

    bool can = false;
    int x, y, z;
    for (int i = 0; i < N - 2; ++i) {
      if (P[i] < P[i + 1] && P[i + 1] > P[i + 2]) {
        can = true; x = i; y = i + 1; z = i + 2;
        break;
      }
    }

    if (can) {
      cout << "YES" << endl;
      cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << endl;
    }
    else cout << "NO" << endl;
  }

  return 0;
}
