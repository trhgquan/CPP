/**
 * VACCINE1 - https://codechef.com/DEC20B/problems/VACCINE1
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int d1, v1, d2, v2, P; cin >> d1 >> v1 >> d2 >> v2 >> P;
  int res = 0;
  vector<int>a(101, 0);

  int i = 1;
  while (1) {
    a[i] = a[i - 1];

    if (i >= d1) a[i] += v1;
    if (i >= d2) a[i] += v2;

    res = i;

    if (a[i] >= P) break;
    ++i;
  }

  cout << res << endl;

  return 0;
}
