#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("BCLKCOUN.inp", ios::in);
ofstream bfile("BCLKCOUN.out", ios::out);

int N, M, total;
string field[10000];

void check (int i, int j)
{
    field[i][j] = '.';
    if (i < N && field[i + 1][j] == 'W')
        check(i + 1, j);
    if (j < M && field[i][j + 1] == 'W')
        check(i, j + 1);
    if (i > 0 && field[i - 1][j] == 'W')
        check(i - 1, j);
    if (j > 0 && field[i][j - 1] == 'W')
        check(i, j - 1);
    if (i > 0 && j > 0 && field[i - 1][j - 1] == 'W')
        check(i - 1, j - 1);
    if (i < N && j < M && field[i + 1][j + 1] == 'W')
        check(i + 1, j + 1);
    if (j > 0 && i < N && field[i + 1][j - 1] == 'W')
        check(i + 1, j - 1);
    if (i > 0 && j < M && field[i - 1][j + 1] == 'W')
        check(i - 1, j + 1);
}

int main () {

    afile >> N >> M;

    for (int i = 0; i < N; i++)
        afile >> field[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (field[i][j] == 'W')
            {
                check(i, j);
                ++total;
            }

    bfile << total;

    afile.close();
    bfile.close();
}
