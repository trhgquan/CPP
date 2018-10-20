#include <iostream>
#include <fstream>

using namespace std;

int W, H, square, max_square;
int a[10000][10000], b[10000][10000];

void check (int i, int j)
{
    a[i][j] = 0;
    b[square][0] = i + 1;
    b[square][1] = j + 1;
    ++square;
    if (i < H && a[i + 1][j] == 1)
        check(i + 1, j);
    if (j < W && a[i][j + 1] == 1)
        check(i, j + 1);
    if (i > 0 && a[i - 1][j] == 1)
        check(i - 1, j);
    if (j > 0 && a[i][j - 1] == 1)
        check(i, j - 1);
}

int main() {
    std::ifstream afile("nilaparvata.inp", std::ios::in);
    std::ofstream bfile("nilaparvata.out", std::ios::out);

    afile >> H >> W;

    max_square = 0;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            afile >> a[i][j];

    for (int i = 0; i < H; i++) {
        square = 0;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == 1)
                check(i,j);
        }
        if (square != 0)
        {
            max_square += square;
            bfile << square;
            for (int k = 0; k < square; k++) {
                bfile << '\t' << "[" << b[k][0] << ", " << b[k][1] << "]";
            }
            bfile << '\n';
        }
    }

    bfile << "Total: " << max_square;

    afile.close();
    bfile.close();
    return 0;
}
