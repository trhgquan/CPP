// THIS FILE GO WITH
// https://drive.google.com/file/d/1O8RLgwivgAduoAGeIYsHLHrziRSEoPMb/view?usp=sharing

#include <iostream>
#include <fstream>

#define max 100

using namespace std;

int N, M, S, F;
bool graph[max][max];
bool Free[max];
int Trace[max];

ifstream afile("GRAPH_DFS.inp", ios::in);
ofstream bfile("GRAPH_DFS.out", ios::out);

void init ()
{
    int u, v;

    afile >> N >> M >> S >> F;

    for (int i = 1; i <= max; i++)
        for (int j = 1; j <= max; j++)
            graph[i][j] = false;

    for (int i = 1; i <= M; i++)
    {
        afile >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }
}

void DFS (int u)
{
    Free[u] = false;

    for (int v = 1; v <= N; v++)
        if (Free[v] && graph[u][v])
        {
            Trace[v] = u;
            DFS(v);
        }
}

void end ()
{
    if (Free[F])
        bfile << -1;
    else
    {
        while (F != S)
        {
            bfile << F << " <- ";
            F = Trace[F];
        }
        bfile << S;
    }
}

int main ()
{
    init();
    for (int i = 1; i <= N; i++)
        Free[i] = true;
    DFS(S);
    end();
    afile.close();
    bfile.close();
}
