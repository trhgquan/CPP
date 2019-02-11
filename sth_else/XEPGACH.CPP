#include <bits/stdc++.h>
#include <string.h>
#include <fstream>

using namespace std;

ifstream afile("XEPGACH.inp", ios::in);
ofstream bfile("XEPGACH.out", ios::out);

int m, n;
int c = 0;
int graph[101][101];
bool mark[101][101];

void read() {
    afile >> m >> n;

    memset(graph, 0, sizeof(graph));
    memset(mark, false, sizeof(mark));

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            afile >> graph[i][j];
}

void check (int i, int j) {
    if (mark[i][j])
        return;

    if (graph[i + 1][j] < graph[i][j] && i + 1 <= m) {
        check(i + 1, j);
        return;
    }

    if (graph[i][j + 1] < graph[i][j] && j + 1 <= n) {
        check(i, j + 1);
        return;
    }

    if (graph[i - 1][j] < graph[i][j] && i - 1 > 0) {
        check(i - 1, j);
        return;
    }

    if (graph[i][j - 1] < graph[i][j] && j - 1 > 0) {
        check(i, j - 1);
        return;
    }

    if (graph[i + 1][j + 1] < graph[i][j] && i + 1 <= m && j + 1 <= n) {
        check(i + 1, j + 1);
        return;
    }

    if (graph[i - 1][j - 1] < graph[i][j] && i - 1 > 0 && j - 1 > 0) {
        check(i - 1, j - 1);
        return;
    }

    if (graph[i + 1][j - 1] < graph[i][j] && i + 1 <= m && j - 1 > 0) {
        check(i + 1, j - 1);
        return;
    }

    if (graph[i - 1][j + 1] < graph[i][j] && i - 1 > 0 && j + 1 <= n) {
        check(i - 1, j + 1);
        return;
    }

    mark[i][j] = true;
    ++c;
}

void print() {
    bfile << c << endl;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (mark[i][j])
                bfile << i << '\t' << j << '\t' << graph[i][j] << endl;
}

int main() {
    read();

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (!mark[i][j])
                check(i, j);

    print();

    afile.close();
    bfile.close();
    return 0;
}
