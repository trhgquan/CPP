#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>

using namespace std;

ofstream bfile("TDBFS.OUT", ios::out);
ifstream afile("TDBFS.INP", ios::in);

int T, n;
queue<int> q;
bool graph[1001][1001];
bool Free[1001];

void DFS(int u);
void BFS(int u);

void Solve() {
    int i, m, u, v;

    afile >> T;

    int t = T;

    while (T--) {
        afile >> n; // number of vertexes

        bfile << "graph " << t - T << endl;

        memset(Free, true, sizeof(Free));

        for (int i = 1; i <= n; ++i){
            afile >> v >> m;

            for (int j = 1; j <= m; ++j) {
                afile >> u;
                graph[v][u] = true;
            }
        }

        while (afile >> u >> v) {
            if (u == 0 && v == 0)
                break;

            if (v == 1){
                BFS(u);
            } else {
                DFS(u);
            }
            bfile << endl;

            // Release all vertexes here
            memset(Free, true, sizeof(Free));
        }
        memset(graph, false, sizeof(graph));
    }
}

int main() {
    Solve();
    return 0;
}

void DFS(int u) {
    Free[u] = false;

    bfile << u << " ";

    for (int i = 1; i <= n; ++i)
        if (graph[i][u] && Free[i]) {
            DFS(i);
        }
}

void BFS(int s) {
    q.push(s);
    Free[s] = false;

    bfile << s << " ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (graph[i][u] && Free[i]) {
                Free[i] = false;
                bfile << i << " ";
                q.push(i);
            }
        }
    }
}
