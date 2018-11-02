#include <iostream>
#include <fstream>
// #include <algorithm>

using namespace std;

int a[10000][10000],f[10000][10000];
int N;
int res;

int min(int a, int b, int c)
{
    a = min(a,b);
    return min(a,c);
}

int square (int n)
{
    return n*n;
}

void Solve()
{
    res = 0;
    for(int i = 2; i <= N*4; i++)
        for (int j = 2; j <= N*4; j++)
        {
            if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1])
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j], f[i][ j- 1]) + 1;
            if (f[i][j] > res)
                res = f[i][j];
        }
}

int main()
{
    ifstream afile("hv.inp", ios::in);
    ofstream bfile("hv.out", ios::out);

    while (!afile.eof())
    {
        if (!(afile >> N))
            return -1;

        for (int i = 1; i <= N*2; i++)
        {
            for (int j = 1; j <= N*2; j++)
            {
                afile >> a[i][j];
                a[i][j + N*2] = a[i][j];
                a[i + N*2][j] = a[i][j];
                a[i + N*2][j + N*2] = a[i][j];
                f[i][j] = 1;
                f[i][j + N*2] = 1;
                f[i + N*2][j] = 1;
                f[i + N*2][j + N*2] = 1;
            }
        }

        Solve();

        bfile << square(res) << '\n';
    }

    afile.close();
    bfile.close();
    return 0;
}
