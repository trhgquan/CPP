/**
 * CHEFWARS - https://www.codechef.com/AUG20B/problems/CHEFWARS
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int H, P; cin >> H >> P;
    cout << (P > H / 2) << endl;
  }

  return 0;
}
