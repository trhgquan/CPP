// PRIM'S ALGORITHM
// FIND THE MINIMUM SPANNING TREE
// FROM A CONNECTED AND NON-DIRECTED GRAPH
#include <iostream>
#include <fstream>
#include <string.h>

#define max 100
#define maxC 10000

using namespace std;

ifstream afile("MINTREE.INP", ios::in);
ofstream bfile("PRIM.OUT", ios::out);

int c[max + 1][max + 1];
int d[max + 1], Trace[max + 1];
int n, m;
bool Free[max + 1];
bool Connected;

void Read () {
    int u, v;
    afile >> n >> m;

    for (u = 1; u <= n; ++u)
        for (v = 1; v <= n; ++v)
            if (u == v) c[u][v] = 0;
            else c[u][v] = maxC;

    for (int i = 1; i <= m; ++i) {
        afile >> u >> v;
        afile >> c[u][v];
        c[v][u] = c[u][v];
    }

    afile.close();
}

void Init () {
    d[1] = 0;
    for (int v = 2; v <= n; ++v) d[v] = maxC;
    memset(Free, true, sizeof(Free));
}

void Prim () {
    int u, min;
    Connected = true;
    for (int k = 1; k <= n; ++k) {
        u = 0; min = maxC;

        for (int i = 1; i <= n; ++i)
            if (Free[i] && d[i] < min) {
                min = d[i];
                u = i;
            }

        if (u == 0) {
            Connected = false;
            break;
        }

        Free[u] = false;
        for (int v = 1; v <= n; ++v)
            if (Free[v] && d[v] > c[u][v]) {
                d[v] = c[u][v];
                Trace[v] = u;
            }
    }
}

void Print () {
    if (!Connected)
        bfile << "Error: Graph is not connected" << endl;
    else {
        bfile << "Minimal spanning tree: " << endl;
        int W = 0;
        for (int v = 2; v <= n; ++v) {
            bfile << "(" << Trace[v] << ", " << v << ") = " << c[Trace[v]][v] << endl;
            W = W + c[Trace[v]][v];
        }
        bfile << "Weight: " << W << endl;
    }
    bfile.close();
}

int main () {
    Read();
    Init();
    Prim();
    Print();
    return 0;
}
