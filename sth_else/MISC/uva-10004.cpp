/**
 * UVA 10004 - Bicoloring
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define MOD 1e9 + 7
#define longint int64_t
#define gms map<int, set<int>>

using namespace std;

gms graph;

void coloring(int vertice, int this_color, vector<int>& color, gms& graph) {
  color[vertice] = this_color;
  int next_color = (this_color == 1) ? 2 : 1;

  int can = 1;
  for (auto v : graph[vertice]) {
    if (color[v] == this_color) {
      can = 0;
      break;
    }
  }

  if (can) {
    for (auto v : graph[vertice]) {
      if (color[v] == 0) coloring(v, next_color, color, graph);
    }
  }

  else {
    color[vertice] = next_color;
    can = 1;
    for (auto v : graph[vertice]) {
      if (color[v] == next_color) {
        can = 0; break;
      }
    }

    if (can) {
      for (auto v : graph[vertice]) {
        if (color[v] == 0) coloring(v, this_color, color, graph);
      }
    }
    else return;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // Code goes here
  while (true) {
    int n; cin >> n;
    if (n == 0) break;

    int e; cin >> e;
    vector<int>color(n, 0);
    gms graph;

    for (int i = 0; i < e; ++i) {
      int u, v; cin >> u >> v;
      graph[u].insert(v);
      graph[v].insert(u);
    }

    int can = 1;
    for (int i = 0; i < n; ++i) {
      if (color[i] == 0) coloring(i, 1, color, graph);
    }

    for (int i = 0; i < n; ++i) {
      if (color[i] == 0) can = 0;
      for (auto v : graph[i]) {
        if (color[v] == color[i]) {can = 0; break;}
      }

      if (!can) break;
    }

    cout << (can ? "BICOLORABLE." : "NOT BICOLORABLE.") << '\n';
  }

  return 0;
}
