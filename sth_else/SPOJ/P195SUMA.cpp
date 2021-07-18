/**
 * P195SUMA - https://www.spoj.com/PTIT/problems/P195SUMA
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int n, k; cin >> n >> k;
  vector<longint>a(n); for (auto& it : a) cin >> it;

  sort(a.begin(), a.end());

  longint res = (k == 0 ? 1 : a[k - 1]);

  longint count = 0;
  int can = 1;
  for (const auto& i : a) {
    if (i <= res) ++count;
    if (count > k) {can = 0; break;}
  }

  cout << (can ? res : -1) << '\n';

  return 0;
}
