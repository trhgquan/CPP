// Find strongly-connected component of a graph
#include <string.h>
#include <iostream>
#include <fstream>
#include <stack>

#define NMAX 10000

using namespace std;

ifstream afile("TARJAN.inp", ios::in);
ofstream bfile("TARJAN.out", ios::out);

stack<int> stk;
bool graph[NMAX][NMAX], Free[NMAX];
int  Num[NMAX], Low[NMAX];
int  N, M, Count = 0, ComCount = 0;

void read() {
    afile >> N >> M;

    memset(graph, false, sizeof(graph));

    for (int i = 1; i <= M; i++) {
        int u, v;
        afile >> u >> v;
        graph[u][v] = true;
    }
}

void visit (int u) {
    Num[u] = Count++;
    Low[u] = Num[u];
    stk.push(u);

    for (int v = 1; v <= N; v++)
        if (Free[v] && graph[u][v])
            if (Num[v] != 0)
                Low[u] = min(Low[u], Num[v]);
        else {
            visit(v);
            Low[u] = min(Low[u], Low[v]);
        }

        if (Num[u] == Low[u]) {
            ComCount++;
            bfile << "Component " << ComCount << '\n';
            int v = -1;
            while (v != u) {
                v = stk.top();
                bfile << v << '\t';
                stk.pop();
                Free[v] = false;
            }
            bfile << '\n';
        }
}

int main () {
    read();

    memset(Num, 0, sizeof(Num));
    memset(Free, true, sizeof(Free));

    for (int i = 1; i <= N; i++)
        if (Num[i] == 0)
            visit(i);

    afile.close();
    bfile.close();
    return 0;
}
