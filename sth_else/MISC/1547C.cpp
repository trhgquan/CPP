/**
 * 1547C - https://codeforces.com/contest/1547/problem/C
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
    int k, n, m; cin >> k >> n >> m;
    vector<int>a(n), b(m);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    int can = 1; vector<int> res;

    while (a.size() > 0 || b.size() > 0) {
      if (a.size() > 0 && b.size() > 0) {
        if (a[0] == 0) {
          res.push_back(0);
          a.erase(a.begin()); ++k;
        }
        else if (b[0] == 0) {
          res.push_back(0);
          b.erase(b.begin()); ++k;
        }
        else if (a[0] > 0 && b[0] > 0) {
          if (a[0] > k && b[0] > k) {can = 0; break;}
          else if (a[0] <= k) {res.push_back(a[0]); a.erase(a.begin());}
          else if (b[0] <= k) {res.push_back(b[0]); b.erase(b.begin());}
        }
      }
      else if (a.size() > 0) {
        if (a[0] == 0) {
          res.push_back(0);
          a.erase(a.begin()); ++k;
        }
        else if (a[0] > 0) {
          if (a[0] > k) {can = 0; break;}
          else if (a[0] <= k) {res.push_back(a[0]); a.erase(a.begin());}
        }
      }
      else if (b.size() > 0) {
        if (b[0] == 0) {
          res.push_back(0);
          b.erase(b.begin()); ++k;
        }
        else if (b[0] > 0) {
          if (b[0] > k) {can = 0; break;}
          else if (b[0] <= k) {res.push_back(b[0]); b.erase(b.begin());}
        }
      }
    }

    if (!can) cout << -1;
    else {
      for (const auto& it : res) cout << it << ' ';
    }
    cout << '\n';
  }

  return 0;
}
