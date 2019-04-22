#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <queue>

#define maxC 10001

using namespace std;

ifstream afile("MAXFLOW.INP", ios::in);
ofstream bfile("FORD-FULKERSON.OUT", ios::out);

int c[101][101], f[101][101];
int Trace[101], Delta[101];
int n, A, B;

void Read() {
    int m, u, v;

    memset(c, 0, sizeof(c));

    afile >> n >> m >> A >> B;
    for (int i = 1; i <= m; ++i){
        afile >> u >> v;
        afile >> c[u][v];
    }
    afile.close();
}

bool findPath() {
    queue<int> q;

    memset(Trace, 0, sizeof(Trace));
    q.push(A);
    Trace[A] = n + 1;
    Delta[A] = maxC;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; ++v) {
            if (Trace[v] == 0) {
                if (f[u][v] < c[u][v]) {
                    Trace[v] = u;
                    Delta[v] = min(Delta[u], c[u][v] - f[u][v]);
                } else {
                    if (f[v][u] > 0) {
                        Trace[v] = -u;
                        Delta[v] = min(Delta[u], f[v][u]);
                    }
                }

                if (Trace[v] != 0) {
                    if (v == B) return true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

void incFlow() {
    int incVal, u, v;

    incVal = Delta[B];
    v = B;
    do {
        u = Trace[v];
        if (u > 0) f[u][v] = f[u][v] + incVal;
        else {
            u = -u;
            f[v][u] = f[v][u] - incVal;
        }
        v = u;
    } while (v != A);
}

void Print() {
    int m = 0;

    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            if (c[u][v] > 0) {
                bfile << "f(" << u << ", " << v << ") = " << f[u][v] << endl;
                if (u == A) m = m + f[A][v];
            }
    bfile << "Max flow: " << m;
    bfile.close();
}

int main() {
    Read();
    memset(f, 0, sizeof(f));
    do {
        if (!findPath()) break;
        incFlow();
    } while (1);
    Print();
    return 0;
}
