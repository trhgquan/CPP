/**
 * https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
 * in a nutshell: find the largest square with 1s only.
 */
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

ifstream afile("LARGEST_SQUARE.inp", ios::in);
ofstream bfile("LARGEST_SQUARE.out", ios::out);

int i_Graph[101][101], s_Graph[101][101];
int R, C;
int g_Max = 0;

int min (int a, int b, int c) {
    int m = a;
    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return m;
}

void read() {
    afile >> R >> C;

    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            afile >> i_Graph[i][j];

    for (int i = 1; i <= R; ++i)
        s_Graph[i][1] = i_Graph[i][1];
    for (int i = 1; i <= C; ++i)
        s_Graph[1][i] = i_Graph[1][i];
}

void Try() {
    g_Max = s_Graph[0][0];
    for (int i = 2; i <= R; ++i)
        for (int j = 2; j <= C; ++j) {
            if (i_Graph[i][j] == 1) {
                s_Graph[i][j] = min(s_Graph[i][j - 1], s_Graph[i - 1][j], s_Graph[i - 1][j - 1]) + 1;

                if (s_Graph[i][j] > g_Max)
                    g_Max = s_Graph[i][j];
            }
            else
                s_Graph[i][j] = 0;
        }
}

void print() {
    // for (int i = 1; i <= R; ++i) {
    //     for (int j = 1; j <= C; ++j)
    //         bfile << s_Graph[i][j] << '\t';
    //     bfile << endl;
    // }

    bfile << g_Max << endl;
}

int main() {
    read();

    Try();

    print();

    afile.close();
    bfile.close();
    return 0;
}
