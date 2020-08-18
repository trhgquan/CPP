/**
 * CRDGAME3 - https://www.codechef.com/AUG20B/problems/CRDGAME3
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int C, R; cin >> C >> R;
    int CN, RN;

    if (C % 9 == 0) CN = C / 9;
    else CN = C / 9 + 1;

    if (R % 9 == 0) RN = R / 9;
    else RN = R / 9 + 1;

    if (CN < RN) cout << 0 << ' ' << CN << endl;
    else cout << 1 << ' ' << RN << endl;
  }

  return 0;
}
