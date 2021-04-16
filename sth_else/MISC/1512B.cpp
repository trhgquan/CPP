/**
 * 1512B - https://codeforces.com/contest/1512/problem/B
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define longint int64_t
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  char graph[401][401];

  // Solution goes here.
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    pair<int, int>point[2];
    int currentPoint = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> graph[i][j];
        if (graph[i][j] == '*') point[currentPoint++] = {i, j};
      }
    }

    graph[point[0].first][point[1].second] = '*';
    graph[point[1].first][point[0].second] = '*';

    if (point[0].second == point[1].second) {
      if (point[0].second < n - 1) {
        graph[point[0].first][point[1].second + 1] = '*';
        graph[point[1].first][point[0].second + 1] = '*';
      } else {
        graph[point[0].first][point[1].second - 1] = '*';
        graph[point[1].first][point[0].second - 1] = '*';
      }
    }

    if (point[0].first == point[1].first) {
      if (point[0].first < n - 1) {
        graph[point[0].first + 1][point[1].second] = '*';
        graph[point[1].first + 1][point[0].second] = '*';
      } else {
        graph[point[0].first - 1][point[1].second] = '*';
        graph[point[1].first - 1][point[0].second] = '*';
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << graph[i][j];
      cout << '\n';
    }
  }
  return 0;
}
