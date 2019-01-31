// DIRECTED GRAPH
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>

#define infinity 10000

using namespace std;

ifstream afile("MINPATH.inp", ios::in);
ofstream bfile("DIJKSTRA.out", ios::out);

int edges, verticles, start, finish;
int graph[100][100];
int D[100], Trace[100];
bool Free[100];


void Read();
void Print();

void Init() {
    for (int i = 1; i <= edges; i++) {
        D[i] = graph[start][i];
        Trace[i] = start;
    }
    memset(Free, true, sizeof(Free));
}

void Dijkstra() {
    int min, u, v;

    do {
        u = 0;
        min = infinity;

        for (int i = 1; i <= edges; i++)
            if (Free[i] && (D[i] < min)) {
                min = D[i];
                u   = i;
            }

        if (u == 0 || u == finish)
            break;

        Free[u] = false;

        for (v = 1; v <= edges; v++)
            if (Free[v] && (D[v] > D[u] + graph[u][v])) {
                D[v] = D[u] + graph[u][v];
                Trace[v] = u;
            }
    } while (!false);
}

int main() {
    Read();
    Init();
    Dijkstra();
    Print();


    afile.close();
    bfile.close();
    return 0;
}

void Read() {
    int u, v;
    afile >> edges >> verticles >> start >> finish;

    for (u = 1; u <= edges; u++)
        for (v = 1; v <= edges; v++) {
            if (u == v)
                graph[u][v] = 0;
            else graph[u][v] = infinity;
        }
    for (int i = 1; i <= verticles; i++) {
        afile >> u >> v;
        afile >> graph[u][v];
    }
}

void Print() {
    if (D[finish] == infinity)
        bfile << "There is no shortest path from " << start << " to " << finish;
    else {
        bfile << "Distance from " << start << " to " << finish << ": " << D[finish] << '\n';

        while (finish != start) {
            bfile << finish << " <- ";
            finish = Trace[finish];
        }

        bfile << start;
    }
}
