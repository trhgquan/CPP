// USING THE TRACE ARRAY.
#include <iostream>
#include <fstream>

#define NMAX 10001

using namespace std;

ifstream afile("COINCHANGE.INP", ios::in);
ofstream bfile("COINCHANGE_3.OUT", ios::out);

int N, M;

// A : Amount of coins,
// V : Value of coins
int C[NMAX], A[NMAX], V[NMAX], T[NMAX];

void Read();
void Write();

void Try() {
    C[0] = 0;

    for (int i = 1; i <= M; ++i)
        C[i] = M + 1;

    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            if (V[j] <= i && C[i - V[j]] + 1 < C[i]) {
                C[i] = C[i - V[j]] + 1;
                A[i] = V[j];
                T[i] = i - V[j];
            }
}

int main() {
    Read();
    Try();
    Write();
    return 0;
}

void Read() {
    afile >> N >> M;

    for (int i = 1; i <= N; ++i)
        afile >> V[i];

    afile.close();
}

void Write() {
    if (C[M] == M + 1)
        bfile << "Cannot solve!" << endl;
    else {
        bfile << C[M] << endl;

        int i = T[M];

        bfile << "Pick the " << A[M] << " coin.\n";

        while (i != 0) {
            bfile << "Pick the " << A[i] << " coin.\n";
            i = T[i];
        }
    }
    bfile.close();
}
