#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream afile("GRAPH_DFS.inp", ios::in);
ofstream bfile("STACK_DFS.out", ios::out);

stack<int> stk;
int n, m, s, e;
int Trace[101];
bool Free[101];
bool Graph[101][101];


void Read() {
    int u, v;
    afile >> n >> m >> s >> e;
    for (int i = 1; i <= n; ++i) Free[i] = true;
    for (int i = 1; i <= m; ++i) {
        afile >> u >> v;
        Graph[u][v] = true;
        Graph[v][u] = true;
    }
    afile.close();
}

void Write() {
    while (e != s) {
        bfile << e << " <- ";
        e = Trace[e];
    }
    bfile << s;
    bfile.close();
}

void DFS() {
    stk.push(s);
    Free[s] = false;

    while (!stk.empty()) {
        // Boolean variable, check if that edge is end.
        bool found = false;

        // Get stack's top.
        int k = stk.top();

        // If the destination is reached, print the path
        if (k == e) Write();

        // Else, check other edges.
        for (int i = 1; i <= n; ++i) {
            if (Free[i] && Graph[i][k]) {
                found = true;
                Free[i] = false;
                Trace[i] = k;
                stk.push(i);
                break;
            }
        }

        // If that edge is end, try next edge at the stack's top
        if (!found) stk.pop();
    }

    // If no path found, print -1.
    bfile << -1;
}

int main(int argc, char const *argv[]) {
    Read();
    DFS();
    return 0;
}
