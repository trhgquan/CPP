// REMEMBER: DIRECTED GRAPH.
#include <bits/stdc++.h>
#include <fstream>

#define infinity 10000

using namespace std;

ifstream afile("MINPATH.inp", ios::in);
ofstream bfile("FORD-BELLMAN.out", ios::out);

int graph[100][100], D[100], Trace[100];
int edges, verticles, Start, Finish;

void Read();
void Print();

void Init() {
    for (int i = 1; i <= edges; i++) {
        D[i] = graph[Start][i];
        Trace[i] = Start;
    }
}

void Ford_Bellman() {
    bool Stop;
    int count = 0;
    int u, v;

    do {
        Stop = true;
        for (u = 1; u <= edges; u++)
            for (v = 1; v <= edges; v++)
                if (D[v] > D[u] + graph[u][v]) {
                    D[v] = D[u] + graph[u][v];
                    Trace[v] = u;
                    Stop = false;
                }
        count++;
    } while (!Stop || (count < edges - 2));
}

int main() {
    Read();
    Init();
    Ford_Bellman();
    Print();

    afile.close();
    bfile.close();
    return 0;
}

void Read() {
    int u, v;
    afile >> edges >> verticles >> Start >> Finish;

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
    if (D[Finish] == infinity)
        bfile << "There are no shortest path from " << Start << " to " << Finish;
    else {
        bfile << "Distance from " << Start << " to " << Finish << ":\t" << D[Finish] << '\n';
        while (Finish != Start) {
            bfile << Finish << " <- ";
            Finish = Trace[Finish];
        }
        bfile << Start;
    }
}
