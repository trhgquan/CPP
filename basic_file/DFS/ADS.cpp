#include <iostream>
#include <fstream>
#include <string.h>

#define MAX 10001

using namespace std;

ifstream afile("ADS.inp", ios::in);
ofstream bfile("ADS.out", ios::out);

int N, M;
int graph[MAX][MAX], total;
bool visited[MAX];

void read() {
    int u, v;
    afile >> N >> M;

    for (int i = 1; i <= M; i++) {
        afile >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void DFS (int u) {
    visited[u] = true;

    for (int i = 1; i <= N; i++)
        if (!visited[i] && graph[u][i] == 1)
            DFS(i);
}

int main() {
    memset(graph, 0, sizeof(graph));
    memset(visited, false, sizeof(visited));

    read();
    total = 0;

    for (int i = 1; i <= N; i++)
        if (!visited[i]) {
            DFS(i);
            total++;
        }

    bfile << (M - N + total);

    afile.close();
    bfile.close();
    return 0;
}
