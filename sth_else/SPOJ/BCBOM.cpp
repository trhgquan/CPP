#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream afile("BCBOM.inp", ios::in);
ofstream bfile("BCBOM.out", ios::out);

int n, m;
char Graph[101][101];
char NumberedGraph[101][101];

void Read() {
    afile >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            afile >> Graph[i][j];

    memset(NumberedGraph, 0, sizeof(NumberedGraph));
}

void Write() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            bfile << NumberedGraph[i][j];
        bfile << endl;
    }
}

int Count(int u, int v) {
    int count = 0;
    if (Graph[u + 1][v] == '*' &&
        u < n) count++;
    if (Graph[u][v + 1] == '*' &&
        v < m) count++;
    if (Graph[u + 1][v + 1] == '*' &&
        u < n && v < m) count++;
    if (Graph[u - 1][v] == '*' &&
        u > 1) count++;
    if (Graph[u][v - 1] == '*' &&
        v > 1) count++;
    if (Graph[u - 1][v - 1] == '*' &&
        u > 1 && v > 1) count++;
    if (Graph[u - 1][v + 1] == '*' &&
        u > 1 && v < m) count++;
    if (Graph[u + 1][v - 1] == '*' &&
        u < n && v > 1) count++;
    return count;
}

void Try() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (Graph[i][j] == '*') NumberedGraph[i][j] = '*';
            else NumberedGraph[i][j] = Count(i, j) + '0';
}

int main(int argc, char const *argv[]) {
    while (true) {
        Read();
        Try();
        Write();
        if (n == 0 || m == 0) break;
    }

    afile.close();
    bfile.close();
    return 0;
}
