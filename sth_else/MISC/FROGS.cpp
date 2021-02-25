/**
 * FROGS - https://codechef.com/FEB21C/problems/FROGS
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
    set<int>frogs;
    vector<int>W(n); for(auto& it : W) {cin >> it; frogs.insert(it);}
    vector<int>L(n); for(auto& it : L) cin >> it;
    map<int, int>position;
    map<int, int>steps;
    for (int i = 1; i <= n; ++i) {
      position[W[i - 1]] = i;
      steps[W[i - 1]] = L[i - 1];
    }

    int res = 0;

    for (auto pivot : frogs) {
      for (auto& pos : position) {
        if (pivot < pos.first && position[pivot] >= pos.second) {
          while (position[pivot] >= pos.second) {
            pos.second += steps[pos.first];
            ++res;
          }
        }
      }
    }

    cout << res << '\n';
  }

  return 0;
}
