/**
 * 1547B - https://codeforces.com/contest/1547/problem/B
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
    string s; cin >> s;
    bool can = true;

    int maxPos = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
      if (s[i] > s[maxPos]) maxPos = i;
    }

    int current = s[maxPos];
    if (maxPos != (int)s.length() - 1 && maxPos != 0) {
      can = 0;
    }
    else {
      while (s.length() > 1) {
        s.erase(s.begin() + maxPos);
        if (s[0] == current - 1) maxPos = 0;
        else if (s[s.length() - 1] == current - 1) maxPos = s.length() - 1;
        else {can = 0; break;}
        current = s[maxPos];
      }
    }

    if (can && current != 'a') can = false;

    cout << (can ? "YES" : "NO") << '\n';
  }

  return 0;
}
