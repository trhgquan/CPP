#include <iostream>
#include <fstream>
#include <string.h>

#define NMAX 101

using namespace std;

ifstream afile("BINARY.INP", ios::in);
ofstream bfile("BINARY.OUT", ios::out);

int N, i;
int X[NMAX];

int main() {
    afile >> N;

    memset(X, 0, sizeof(X));

    do {
        for (i = 1; i <= N; ++i)
            bfile << X[i];
        bfile << endl;

        i = N;

        while (i > 0 && X[i] == 1) i--;
        if (i > 0) {
            X[i] = 1;
            for (int j = i + 1; j <= N; ++j)
                X[j] = 0;
        }
    } while (i != 0);

    afile.close();
    bfile.close();
    return 0;
}
