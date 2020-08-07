/**
* 1399A - https://codeforces.com/problemset/problem/1399/A
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
    sort(A.begin(), A.end());

    bool can = true;
    for (int i = 0; i < N - 1; ++i)
      if (A[i + 1] - A[i] > 1) {can = false; break;}

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
