/**
 * DIVTHREE - https://www.codechef.com/JAN21C/problems/DIVTHREE
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    int n, k, d; cin >> n >> k >> d;
    int a = 0; for (int i = 1; i <= n; ++i) {int u; cin >> u; a += u;}

    cout << ((a / k > d) ? d : a / k) << endl;
  }

  return 0;
}
