#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int W, H, square, max_square, max_zone = 1;
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
        for (int j = 0; j < W; j++) {
            square = 0;
            if (a[i][j] == 1) {
                check(i,j);
                bfile << square;
                for (int i = 0; i < square; i++) {
                    bfile << " [" << b[i][0] << ", " << b[i][1] << "]";
                }
                bfile << '\n';
            }
            max_square += square;
        }
    }

    bfile << max_square;

    afile.close();
    bfile.close();
    return 0;
}
