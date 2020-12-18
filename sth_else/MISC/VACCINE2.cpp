/**
 * VACCINE2 - https://codechef.com/DEC20B/problems/VACCINE2
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, d; cin >> n >> d;
    int atRisk, notRisk; atRisk = notRisk = 0;

    for (int i = 1; i <= n; ++i) {
      int u; cin >> u;
      (u >= 80 || u <= 9) ? ++atRisk : ++notRisk;
    }

    cout << (int)ceil(atRisk * 1.0 / d * 1.0) + (int)ceil(notRisk * 1.0 / d * 1.0) << endl;
  }

  return 0;
}
