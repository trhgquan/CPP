/**
 * 1520A - https://codeforces.com/contest/1520/problem/A
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
    int n; cin >> n;
    string s; cin >> s;

    map<char, int> m;
    int can = 1;
    m[s[0]]++; char prev_char = s[0];
    for (char i : s) {
      if (m[i] == 0 || (m[i] > 0 && prev_char == i)) {
        ++m[i];
        prev_char = i;
      }
      else {can = 0; break;}
    }

    cout << (can ? "YES" : "NO") << '\n';
  }

  return 0;
}
