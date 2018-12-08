// 1 route, over all edges, back to where we start.
#include <iostream>
#include <fstream>
#include <string.h>

#define MAX 1001

using namespace std;

ifstream afile("HAMILTON.inp", ios::in);
ofstream bfile("HAMILTON.out", ios::out);

int n, m;
int hamilton_route[MAX];
bool graph[MAX][MAX], visited[MAX];

void read() {
    int u, v;
    afile >> n >> m;

    for (int i = 1; i <= m; i++) {
        afile >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
}

void print() {
    for (int i = 1; i <= n; i++)
        bfile << hamilton_route[i] << '\t';
    bfile << hamilton_route[1] << '\n';
}

void hamilton (int u) {
    for (int i = 1; i <= n; i++)
        if (!visited[i] && graph[hamilton_route[u - 1]][i]) {
            hamilton_route[u] = i;
            if (u < n) {
                visited[i] = true;
                hamilton(u + 1);
                visited[i] = false;
            } else
                if (graph[i][hamilton_route[1]])
                    print();
        }
}

int main() {
    memset(graph, false, sizeof(graph));

    read();
    memset(visited, false, sizeof(visited));

    hamilton_route[1] = 1;
    visited[1] = true;

    hamilton(2);

    return 0;
}
