/**
 * CDHNT3 - https://www.codechef.com/CHNT2021/problems/CDHNT3
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  // Solution goes here.
  priority_queue<int, vector<int>, greater<int>>trees;
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {int u; cin >> u; trees.push(u);}

  while (!trees.empty()) {
    cout << trees.size() << '\n';
    int currentTop = trees.top(); trees.pop();
    while (!trees.empty() && trees.top() == currentTop) trees.pop();
  }

  return 0;
}
