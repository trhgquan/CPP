#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

ifstream afile("HFLOOR.inp", ios::in);
ofstream bfile("HFLOOR.out", ios::out);

int T, N, M, people, rooms;
string graph[101];

void check (int u, int v);

int main () {
    afile >> T;
    bfile << fixed << setprecision(2);

    while (T--) {
        people = 0; rooms = 0;
        afile >> N >> M;
        for (int i = 1; i <= N; i++) {
            afile >> graph[i];
        }
        for (int i = 1; i <= N; i++)
            for (int j = 0; j < M; j++)
                if (graph[i][j] != '#') {
                    check(i, j);
                    ++rooms;
                }
        float result = (float)people / (float)rooms;
        bfile << result << '\n';
    }

    afile.close();
    bfile.close();
    return 0;
}

void check (int u, int v) {
    if (graph[u][v] == '*')
        ++people;
    graph[u][v] = '#';

    if (graph[u + 1][v] != '#' && u < N)
        check(u + 1, v);
    if (graph[u][v + 1] != '#' && v < M)
        check(u, v + 1);
    if (graph[u - 1][v] != '#' && u > 0)
        check(u - 1, v);
    if (graph[u][v - 1] != '#' && v > 0)
        check(u, v - 1);
}
