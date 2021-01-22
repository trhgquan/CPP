/**
 * 1473B - https://codeforces.com/contest/1473/problem/B
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

longint GCD(longint a, longint b) {
  longint c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

longint LCM(longint a, longint b) {
  return a * b / GCD(a, b);
}

bool isSubstring(string a, string b) {
  size_t index = 0;
  while ((index = b.find(a)) != string::npos) {
    if (index != 0) return false;
    b.erase(0, index + a.length());
  }
  return (b.length() == 0);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  int q; cin >> q;
  while (q--) {
    string s, t; cin >> s >> t;
    longint l = LCM(s.length(), t.length());

    string res = "";
    for (int i = 1; i <= l; i += min(s.length(), t.length())) res += ((s.length() > t.length()) ? t : s);

    cout << ((isSubstring(s, res) && isSubstring(t, res)) ? res : "-1") << endl;
  }

  return 0;
}
