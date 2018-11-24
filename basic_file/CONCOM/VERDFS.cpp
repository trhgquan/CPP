// Find vertices of a graph.
#include <iostream>
#include <fstream>
#include <string.h>

#define NMAX 10000

using namespace std;

ifstream afile("VERDFS.inp", ios::in);
ofstream bfile("VERDFS.out", ios::out);

int N, M, Count = 0, LOW[NMAX], NUM[NMAX], NUMChild[NMAX]; // with NUMChild is NUM's child.
bool graph[NMAX][NMAX], isVertex[NMAX];

void read () {
    int u, v;

    memset(graph, false, sizeof(graph));
    memset(isVertex, false, sizeof(isVertex));
    memset(NUM, 0, sizeof(NUM));

    afile >> N >> M;

    for (int i = 1; i <= M; i++) {
        afile >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
}

void write () {
    for (int i = 1; i <= N; i++)
        if (isVertex[i])
            bfile << i << '\t';
}

void visit (int u) {
    Count++;
    NUM[u] = Count;
    LOW[u] = N + 1;
    NUMChild[u] = 0;

    for (int v = 1; v <= N; v++)
        if (graph[u][v]) {
            if (NUM[v] == 0) {
                NUMChild[u]++;
                visit(v);
                isVertex[u] = ((LOW[v] >= NUM[u]) ? true : isVertex[u]);
                LOW[u] = min(LOW[u], LOW[v]);
            } else LOW[u] = min(NUM[v], LOW[u]);
        }
}

int main () {
    read();

    for (int u = 1; u <= N; u++)
        if (NUM[u] == 0) {
            visit(u);
            if (NUMChild[u] < 2)
                isVertex[u] = false;
        }

    write();

    afile.close();
    bfile.close();
    return 0;
}
