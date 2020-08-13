/**
 * 1395A  - https://codeforces.com/problemset/problem/1395/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // Code goes here.
  int T; cin >> T;
  while (T--) {
    int r, g, b, w; cin >> r >> g >> b >> w;

    bool can = false;

    if ((r % 2 == 0 && g % 2 == 0 && b % 2 == 0) ||
        (g % 2 == 0 && b % 2 == 0 && w % 2 == 0) ||
        (b % 2 == 0 && w % 2 == 0 && r % 2 == 0) ||
        (w % 2 == 0 && r % 2 == 0 && g % 2 == 0)) {
          can = true;
    } else {
      if (r > 0 && g > 0 && b > 0) {
        --r; --g; --b; w += 3;

        if ((r % 2 == 0 && g % 2 == 0 && b % 2 == 0) ||
              (g % 2 == 0 && b % 2 == 0 && w % 2 == 0) ||
              (b % 2 == 0 && w % 2 == 0 && r % 2 == 0) ||
              (w % 2 == 0 && r % 2 == 0 && g % 2 == 0)) {
          can = true;
        }
      }
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
