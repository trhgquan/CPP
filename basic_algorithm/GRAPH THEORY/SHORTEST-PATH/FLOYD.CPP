// FLOYD ALGORITHM: SHORTEST PATH IN DIRECTED GRAPH.
#include <bits/stdc++.h>
#include <fstream>

#define infinity 10001

using namespace std;

ifstream afile("MINPATH.inp", ios::in);
ofstream bfile("FLOYD.out", ios::out);

int c[101][101], Trace[101][101];
int n, S, F;

void Read() {
    int u, v, m;

    afile >> n >> m >> S >> F;

    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v) {
            if (u == v)
                c[u][v] = 0;
            else c[u][v] = infinity;
        }

    for (int i = 1; i <= m; ++i) {
        afile >> u >> v;
        afile >> c[u][v];
    }
}

void Floyd() {
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            Trace[u][v] = v;

    for (int k = 1; k <= n; ++k)
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                if (c[u][v] > c[u][k] + c[k][v]) {
                    c[u][v] = c[u][k] + c[k][v];
                    Trace[u][v] = Trace[u][k];
                }
}

void Write() {
    if (c[S][F] == infinity)
        bfile << "Path from " << S << " to " << F << " not found";
    else {
        bfile << "Distance from " << S << " to " << F << " is " << c[S][F] << endl;
        do {
            bfile << S << " -> ";
            S = Trace[S][F];
        } while (S != F);
        bfile << F;
    }
    afile.close();
    bfile.close();
}

int main() {
    Read();
    Floyd();
    Write();

    return 0;
}
