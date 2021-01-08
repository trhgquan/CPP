/**
 * 1472D - https://codeforces.com/contest/1472/problem/D
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  longint t; cin >> t;
  while (t--) {
    longint n; cin >> n;
    multiset<longint>s;
    for (int i = 0; i < n; ++i) {longint u; cin >> u; s.insert(u);}

    longint bob = 0; longint alice = 0;
    longint index = 0;
    while (s.size() > 0) {
      if (index % 2 == 0) {
        if (*prev(s.end()) % 2 == 0) alice += *prev(s.end());
      }
      else {
        if (*prev(s.end()) % 2 != 0) bob += *prev(s.end());
      }

      s.erase(prev(s.end()));
      ++index;
    }

    cout << ((alice == bob) ? "Tie" : ((alice > bob) ? "Alice" : "Bob")) << endl;
  }

  return 0;
}
