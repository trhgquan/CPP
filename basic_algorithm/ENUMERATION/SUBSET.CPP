#include <iostream>
#include <fstream>

#define NMAX 101

using namespace std;

ifstream afile("SUBSET.INP", ios::in);
ofstream bfile("SUBSET.OUT", ios::out);

int N, K, i;
int X[NMAX];

int main() {
    afile >> N >> K;

    // Generate a set of numbers from 1 to k
    for (i = 1; i <= K; ++i)
        X[i] = i;

    do {
        bfile << "(";
        for (i = 1; i <= K - 1; ++i)
            bfile << X[i] << ", ";
        bfile << X[K] << ")\n";

        i = K;

        while (i > 0
            && X[i] == N - K + i) i--;
        if (i > 0) {
            X[i]++;
            for (int j = i + 1; j <= K; ++j)
                X[j] = X[j - 1] + 1;
        }
    } while (i != 0);

    afile.close();
    bfile.close();
    return 0;
}
