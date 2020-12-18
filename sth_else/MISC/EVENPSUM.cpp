/**
 * EVENPSUM - https://www.codechef.com/DEC20B/problems/EVENPSUM
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  longint t; cin >> t;
  while (t--) {
    longint a, b; cin >> a >> b;
    longint ea, eb, oa, ob; ea = eb = oa = ob = 0;
    ea = ((a % 2 == 0) ? a / 2 : (a - 1) / 2);
    eb = ((b % 2 == 0) ? b / 2 : (b - 1) / 2);
    oa = ((a % 2 != 0) ? (a + 1) / 2 : a / 2);
    ob = ((b % 2 != 0) ? (b + 1) / 2 : b / 2);

    cout << (ea * eb) + (oa * ob) << endl;
  }

  return 0;
}
