/**
 * BMI - https://www.codechef.com/CCRC21B/problems/BMI
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

template<class T>
T quickPow(T x, T n) {
  if (n == 1) return x;
  if (n % 2 == 0) return quickPow(x * x, n / 2);
  return x * quickPow(x * x, (n - 1) / 2);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    int m, h; cin >> m >> h;
    double BMI = (double)m / (double)quickPow(h, 2);
    if (BMI <= 18.0) cout << 1 << '\n';
    else if (BMI >= 19.0 && BMI <= 24.0) cout << 2 << '\n';
    else if (BMI >= 25.0 && BMI <= 29.0) cout << 3 << '\n';
    else cout << 4 << '\n';
  }

  return 0;
}
