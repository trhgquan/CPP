#include <iostream>
#include <fstream>
#include <vector>

#define MAX 10001

using namespace std;

ifstream afile("PT07Y.inp", ios::in);
ofstream bfile("PT07Y.out", ios::out);

int N, M;
int count = 0;
int graph[MAX][MAX];
bool visit[MAX];

void DFS (int u)
{
    visit[u] = true;
    count++;

    for (int i = 1; i <= graph[u][0]; i++)
    {
        int v = graph[u][i];
        if (!visit[v])
            DFS(v);
    }
}

int main()
{
    afile >> N >> M;

    if (M == 0)
        bfile << "NO";
    else
    {
        for (int i = 0; i <= N; i++)
        {
            visit[i] = false;
            for (int j = 0; j <= N; j++)
                graph[i][j] = 0;
        }

        for (int i = 0; i <= N; i++)
        {
            int a, b, m;
            afile >> a >> b;

            m = ++graph[a][0];
            graph[a][m] = b;

            m = ++graph[b][0];
            graph[b][m] = a;
        }

        if (M == N - 1)
        {
            DFS(1);
            bfile << ((count == N) ? "YES" : "NO");
        }
        else bfile << "NO";
    }

    return 0;
}
