#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ifstream afile("COUNTISL.inp", ios::in);
ofstream bfile("COUNTISL.out", ios::out);

int T, n, m;
string graph[201];

void check (int u, int v);

int main () {
    afile >> T;
    int max;

    while (T--) {
        max = 0;
        afile >> n >> m;
        for (int i = 1; i <= n; i++)
            afile >> graph[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (graph[i][j] == '#') {
                    check(i, j);
                    ++max;
                }


        bfile << max << '\n';
    }

    afile.close();
    bfile.close();
    return 0;
}

void check (int u, int v) {
    graph[u][v] = '.';

    if (u > 0 && graph[u - 1][v] == '#')
        check(u - 1, v);
    if (v > 0 && graph[u][v - 1] == '#')
        check(u, v - 1);
    if (u < n && graph[u + 1][v] == '#')
        check(u + 1, v);
    if (v < m && graph[u][v + 1] == '#')
        check(u, v + 1);
    if (u > 0 && v > 0 && graph[u - 1][v - 1] == '#')
        check(u - 1, v - 1);
    if (u < n && v < m && graph[u + 1][v + 1] == '#')
        check(u + 1, v + 1);
    if (u < n && v > 0 && graph[u + 1][v - 1] == '#')
        check(u + 1, v - 1);
    if (u > 0 && v < m && graph[u - 1][v + 1] == '#')
        check(u - 1, v + 1);
}
