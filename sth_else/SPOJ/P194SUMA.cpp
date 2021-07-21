/**
 * P194SUMA - https://www.spoj.com/PTIT/problems/P194SUMA
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

  longint res = 0;
  vector<longint> negative, positive;
  for (int i = 0; i < n; ++i) {
    longint u; cin >> u;
    if (u >= 0) positive.push_back(u);
    else negative.push_back(u);
  }

  sort(negative.begin(), negative.end());

  if (negative.size() > 0) {
    for (int i = 0; i < (int)negative.size() && k > 0; --k, ++i) {
      negative[i] = -negative[i];
    }

    for (const longint& i : negative) {
      positive.push_back(i);
    }
  }

  sort(positive.begin(), positive.end());

  if (k > 0) positive[0] *= (k % 2 ? -1 : 1);

  for (const longint& i : positive) res += i;

  cout << res;

  return 0;
}
