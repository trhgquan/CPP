/**
 * 1395B  - https://codeforces.com/problemset/problem/1395/B
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int visited[101][101];

void visit(int x, int y, int n, int m) {
  cout << x <<  ' ' << y << endl;
  visited[x][y] = 1;

  for (int i = 1; i <= m; ++i) {
    if (!visited[x][i]) {
      visit(x, i, n, m);
      return;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!visited[i][y]) {
      visit(i, y, n, m);
      return;
    }
  }
}

int main() {
  // freopen("test.dat", "r+", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // Code goes here.
  int n, m, x, y; cin >> n >> m >> x >> y;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      visited[i][j] = 0;

  visit(x, y, n, m);

  return 0;
}
