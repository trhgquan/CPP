// THE KRUSKAL ALGORITHM:
// FIND THE MINIMUM SPANNING TREE
// FROM A CONNECTED AND DIRECTED GRAPH
#include <bits/stdc++.h>
#include <fstream>

#define maxV 100
#define maxE (maxV - 1) * maxV / 2

using namespace std;

ifstream afile("MINTREE.INP", ios::in);
ofstream bfile("KRUSKAL.OUT", ios::out);

struct TEdge {
    int u, v, c;
    bool mark;
};

TEdge e[maxE + 1];
int Lab[maxV + 1];
int n, m;
bool Connected;

void Read() {
    afile >> n >> m;
    for (int i = 1; i <= m; ++i)
        afile >> e[i].u >> e[i].v >> e[i].c;
}

void Init() {
    for (int i = 1; i <= n; ++i) Lab[i] = -1;
    for (int i = 1; i <= m; ++i) e[i].mark = false;
}

int getRoot (int v) {
    while (Lab[v] > 0)
        v = Lab[v];
    return v;
}

void Union (int r1, int r2) {
    int x = Lab[r1] + Lab[r2];

    if (Lab[r1] > Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    } else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}

void adjustHeap (int root, int last) {
    TEdge Key = e[root];
    int child;

    while (root * 2 <= last) {
        child = root * 2;
        if (child < last && e[child + 1].c < e[last].c)
            child++;
        if (Key.c <= e[child].c)
            break;
        e[root] = e[child];
        root = child;
    }
    e[root] = Key;
}

void Kruskal () {
    int count = 0, r1, r2;
    TEdge tmp;
    Connected = false;

    for (int i = m / 2; i >= 1; --i)
        adjustHeap(i, m);
    for (int i = m - 1; i >= 0; --i) {
        tmp = e[1]; e[1] = e[i + 1]; e[i + 1] = tmp;
        adjustHeap(1, i);
        r1 = getRoot(e[i + 1].u); r2 = getRoot(e[i + 1].v);
        if (r1 != r2) {
            e[i + 1].mark = true;
            count++;
            if (count == n - 1) {
                Connected = true;
                return;
            }
            Union(r1, r2);
        }
    }
}

void Print () {
    if (!Connected)
        bfile << "Error: Graph is not connected" << endl;
    else {
        bfile << "Minimal spanning tree: " << endl;
        int count = 0, w = 0;
        for (int i = 1; i <= m; ++i) {
            if (e[i].mark) {
                bfile << "(" << e[i].u << ", " << e[i].v << ") = " << e[i].c << endl;
                count++;
                w = w + e[i].c;
            }
            if (count == n - 1)
                break;
        }
        bfile << "Weight: " << w;
    }

    afile.close();
    bfile.close();
}

int main () {
    Read();
    Init();
    Kruskal();
    Print();

    return 0;
}
