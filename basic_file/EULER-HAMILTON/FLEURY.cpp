// FLEURY algorithm - Euler graph: 1 route, over all edges, back to where we start.
#include <iostream>
#include <fstream>
#include <stack>
#include <string.h>

#define NMAX 101

using namespace std;

ifstream afile("FLEURY.inp", ios::in);
ofstream bfile("FLEURY.out", ios::out);

int graph[NMAX][NMAX], VER[NMAX];
int n, count = 0;

stack<int> stk;

void read();
void print();

int main() {
    read();

    stk.push(1);

    while (!stk.empty()) {
        int u = stk.top();
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] > 0) {
                graph[u][v]--;
                graph[v][u]--;
                stk.push(v);
                break;
            }
        }
        if (stk.top() == u) {
            VER[count] = stk.top();
            count++;
            stk.pop();
        }
    }

    print();

    afile.close();
    bfile.close();
    return 0;
}

void read() {
    int u, v, k;

    memset(graph, 0, sizeof(graph));

    afile >> n;
    while (afile >> u >> v >> k) {
        graph[u][v] = k;
        graph[v][u] = k;
    }
}

void print() {
    for (int i = count - 1; i >= 0; i--) {
        bfile << VER[i] << '\t';
    }
}
