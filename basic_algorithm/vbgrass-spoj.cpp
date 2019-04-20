#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int R, C, ans = 0;
string a[10000];

void check (int i, int j)
{
    a[i][j] = '.';
    if (i < R && a[i + 1][j] == '#')
        check(i + 1, j);
    if (j < C && a[i][j + 1] == '#')
        check(i, j + 1);
    if (i > 0 && a[i - 1][j] == '#')
        check(i - 1, j);
    if (j > 0 && a[i][j - 1] == '#')
        check(i, j - 1);
}

int main() {
    std::ifstream afile("vbgrass-spoj.inp", std::ios::in);
    std::ofstream bfile("vbgrass-spoj.out", std::ios::out);

    afile >> R >> C;

    for (int i = 0; i < R; i++)
        afile >> a[i];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (a[i][j] == '#') {
                check(i, j);
                ++ans;
            }

    bfile << ans;

    afile.close();
    bfile.close();
    return 0;
}
