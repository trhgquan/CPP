#include <iostream>
#include <fstream>
#include <vector>

#define MAX 10001

using namespace std;

bool check[MAX] = {false};
int total = 0;

ifstream afile("PT07Z.inp", ios::in);
ofstream bfile("PT07Z.out", ios::out);

int dfs (vector<int> a[], int root)
{
    int m, m1 = -1, m2 = -1;

    check[root] = 1;

    for (int i = 0; i < a[root].size(); i++)
    {
        if (!check[a[root][i]])
        {
            m = dfs(a, a[root][i]);
            if (m >= m1)
            {
                m2 = m1;
                m1 = m;
            }
            else if (m > m2)
                m2 = m;
        }
    }
    total = max(total , m1+m2+2);
    return (m1 + 1);
}

int main ()
{
    int N, A, B;

    afile >> N;

    vector<int> graph[N + 1];

    for (int i = 0; i < N - 1; i++)
    {
        afile >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    dfs(graph, 1);

    bfile << total;

    afile.close();
    bfile.close();
}
