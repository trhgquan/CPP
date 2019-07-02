#include <iostream>
#include <fstream>

#define NMAX 101

using namespace std;

ifstream afile("NQUEENS.INP", ios::in);
ofstream bfile("NQUEENS.OUT", ios::out);

// Chessboard nxn
int n, count;
int x[NMAX];
bool a[NMAX], b[NMAX], c[NMAX];

void Init() {
    afile >> n;
    afile.close();

    // First there are no solution.
    count = 0;

    // All columns is free
    for (int i = 1; i <= n; ++i)
        a[i] = true;
    for (int i = 2; i <= 2 * n; ++i)
        b[i] = true;
    for (int i = 1 - n; i <= 1 + n; ++i)
        c[i] = true;
}

void Write() {
    count++;
    for (int i = 1; i <= n; ++i)
        bfile << "(" << i << "," <<  x[i] << ") ";
    bfile << endl;
}

void Try (int i) {
    for (int j = 1; j <= n; ++j) {
        if (a[j] && b[i + j] && c[i - j]) {
            x[i] = j;

            if (i == n) Write();
            else {
                a[j] = false; b[i + j] = false; c[i - j] = false;
                Try(i + 1);
                a[j] = true; b[i + j] = true; c[i - j] = true;
            }
        }
    }
}

void End() {
    if (count == 0)
        bfile << "No solution!" << endl;
    else bfile << "Total: " << count << " solutions";
    bfile.close();
}

int main() {
    Init();
    Try(1);
    End();
    return 0;
}
