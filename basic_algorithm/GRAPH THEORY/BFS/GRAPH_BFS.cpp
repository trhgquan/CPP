#include <iostream>
#include <fstream>
#include <queue>

#define NMAX 100

using namespace std;

ifstream afile("GRAPH_BFS.inp", ios::in);
ofstream bfile("GRAPH_BFS.out", ios::out);

int graph[NMAX][NMAX];
queue<int> q;

int N, M, U, V, S, F, Trace[NMAX], Free[NMAX];

void BFS (int s) {
    q.push(s);
    Free[s] = 0;
    while (!q.empty()) {
        int u = q.front(); // aka get the 1st item of the queue
        q.pop(); // aka delete the 1st item of the queue

        for (int v = 1; v <= N; v++)
            if (Free[v] && graph[u][v] == 1) {
                Free[v] = 0;
                Trace[v] = u;
                q.push(v); // aka insert this item to the end of the queue
            }
    }
}

void end () {
    if (Free[F])
        bfile << -1;
    else {
        while (F != S) {
            bfile << F << " <- ";
            F = Trace[F];
        }
        bfile << S;
    }
}

int main () {
    afile >> N >> M >> S >> F;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            graph[i][j] = 0;

    for (int i = 1; i <= M; i++) {
        afile >> U >> V;
        graph[U][V] = 1;
        graph[V][U] = 1;
    }

    for (int i = 1; i <= N; i++)
        Free[i] = 1;

    BFS(S);
    end();

    afile.close();
    bfile.close();
}
