#include <iostream>
#include <fstream>
#include <string.h>

#define NMAX 10000

using namespace std;

ifstream afile("WARSHALL.inp", ios::in);
ofstream bfile("WARSHALL.out", ios::out);

bool Free[NMAX];
bool Graph[NMAX][NMAX];
int  n, m, count = 1;

void read () {
    int u, v;

    afile >> n >> m;

    memset(Graph, false, sizeof(Graph));
    memset(Free, true, sizeof(Free));

    for (int i = 1; i <= m; i++) {
        afile >> u >> v;
        Graph[u][v] = true;
        Graph[v][u] = true;
    }
}

void DFS (int u) {
    bfile << u << '\t';
    Free[u] = false;

    for (int v = 1; v <= n; v++) {
        if (Free[v] && Graph[u][v]) {
            DFS(v);
        }
    }
}

int main () {
    read();

    for (int v = 1; v <= n; v++) {
        if (Free[v]) {
            bfile << "Component " << count << '\n';
            DFS(v);
            count++;
            bfile << '\n';
        }
    }

    afile.close();
    bfile.close();
    return 0;
}
