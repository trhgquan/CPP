#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <queue>

#define maxC 10001

using namespace std;

ifstream afile("MAXFLOW.INP", ios::in);
ofstream bfile("MAXFLOW.OUT", ios::out);

// f = flow, c = capacity
int c[101][101], f[101][101], cf[101][101];
int Trace[101];
int n, A, B;

void Read() {
    int m, u, v;
    memset(c, 0, sizeof(c));
    afile >> n >> m >> A >> B;
    for (int i = 1; i <= m; ++i) {
        afile >> u >> v;
        afile >> c[u][v];
    }

    afile.close();
}

void CreateGf() {
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            cf[u][v] = maxC;
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            if (c[u][v] > 0) {
                if (f[u][v] < c[u][v])
                    cf[u][v] = c[u][v] - f[u][v];
                if (f[u][v] > 0)
                    cf[v][u] = -f[u][v];
            }
}

bool findPath() {
    queue<int> q;
    bool Free[101];

    memset(Free, true, sizeof(Free));
    q.push(A);
    Free[A] = false;

	// BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; ++v)
            if (Free[v] && cf[u][v] != maxC) {
                Trace[v] = u;
                if (v == B) return true;
                Free[v] = false;
                q.push(v);
            }
    }
    return false;
}

void incFlow() {
    int u, v, incVal;

    incVal = maxC;
    v = B;
    while (v != A) {
        u = Trace[v];
        if (abs(cf[u][v]) < incVal)
            incVal = abs(cf[u][v]);
        v = u;
    }

    v = B;
    while (v != A) {
        u = Trace[v];
        if (cf[u][v] > 0) f[u][v] = f[u][v] + incVal;
        else f[v][u] = f[v][u] - incVal;
        v = u;
    }
}

void Write() {
    int m = 0;
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            if (c[u][v] > 0) {
                bfile << "f(" << u << ", " << v <<  ") = " << f[u][v] << endl;
                if (u == A) m = m + f[A][v];
            }
    bfile << "Max flow: " << m;
    bfile.close();
}

int main () {
    Read();
    memset(f, 0, sizeof(f));
    do {
        CreateGf();
        if (!findPath()) break;
        incFlow();
    } while (1);
    Write();

    return 0;
}
