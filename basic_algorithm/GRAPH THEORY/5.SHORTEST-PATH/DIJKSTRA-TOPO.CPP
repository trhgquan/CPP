// DIJKSTRA ALGORITHM
// WITH TOPOLOGICAL SHORT.
#include <iostream>
#include <fstream>
#include <string.h>

#define infinity 10000

using namespace std;

ifstream afile("MINPATH.inp", ios::in);
ofstream bfile("DIJKSTRA-TOPO.out", ios::out);

int c[101][101];
int List[101], d[101], Trace[101];
int n, S, F, count;

void Read () {
    int m, u, v;
    afile >> n >> m >> S >> F;

    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            if (u == v) c[u][v] = 0;
            else c[u][v] = infinity;

    for (int i = 1; i <= m; ++i) {
        afile >> u >> v;
        afile >> c[u][v];
    }

    afile.close();
}

// Number the edges, using topological ways
void Number () {
    int deg[101];
    int u, v, front;

    memset(deg, 0, sizeof(deg));
    for (u = 1; u <= n; ++u)
        for (v = 1; v <= n; ++v)
            if (v != u && c[v][u] < infinity) deg[u]++;

    count = 0;

    for (u = 1; u <= n; ++u)
        if (deg[u] == 0) {
            count++;
            List[count] = u;
        }

    front = 1;

    while (front <= count) {
        u = List[count];
        front++;

        for (v = 1; v <= n; ++v)
            if (c[u][v] != infinity) {
                deg[v]--;
                if (deg[v] == 0) {
                    count++;
                    List[count] = v;
                }
            }
    }
}

void Init () {
    for (int i = 1; i <= n; ++i) d[i] = infinity;
    d[S] = 0;
}

void findPath () {
    int u, v;
    for (int i = 1; i <= n - 1; ++i)
        for (int j = i + 1; j <= n; ++j) {
            u = List[i]; v = List[j];
            if (d[v] > d[u] + c[u][v]) {
                d[v] = d[u] + c[u][v];
                Trace[v] = u;
            }
        }
}

void Write () {
    if (d[F] == infinity)
        bfile << "Path from " << S << " to " << F << " not found" << endl;
    else {
        bfile << "Distance from " << S << " to " << F << ": " << d[F] << endl;
        while (F != S) {
            bfile << F << " <- ";
            F = Trace[F];
        }
        bfile << S << endl;
    }
    bfile.close();
}

int main () {
    Read();
    Number();
    Init();
    findPath();
    Write();
    return 0;
}
