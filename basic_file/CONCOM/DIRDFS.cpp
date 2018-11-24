// Directing a graph by using DFS.
// Also means to find bridges in a graph.
#include <iostream>
#include <fstream>
#include <string.h>

#define NMAX 10000

using namespace std;

ifstream afile("DIRDFS.inp", ios::in);
ofstream bfile("DIRDFS.out", ios::out);

int  N, M, Count = 0;
bool graph[NMAX][NMAX];
int  NUM[NMAX], LOW[NMAX];

void read () {
    int u, v;

    afile >> N >> M;

    memset(graph, false, sizeof(graph));

    for (int i = 1; i <= M; i++) {
        afile >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
}

void visit (int u) {
    Count++;
    NUM[u] = Count;
    LOW[u] = N + 1;

    for (int v = 1; v <= N; v++) {
        if (graph[u][v]) {
            // (u,v) now is a one-direct vector.
            graph[v][u] = false;
            // if v is not visited.
            if (NUM[v] == 0) {
                // then visit v.
                visit(v);
                if (LOW[v] > NUM[u])
                    // u,v is a "bridge".
                    bfile << "(" << u << "," << " " << v << ")" << '\n';
                // minimize LOW[u].
                LOW[u] = min(LOW[u], LOW[v]);
            } else
                // minimize LOW[u].
                LOW[u] = min(NUM[v], LOW[u]);
        }
    }
}

int main () {
    read();

    bfile << "Bridges:" << '\n';

    for (int u = 1; u <= N; u++)
        if (NUM[u] == 0)
            visit(u);

    bfile << "Directed bridge:" << '\n';

    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            if (graph[u][v])
                bfile << u << " -> " << v << '\n';

    afile.close();
    bfile.close();
    return 0;
}
