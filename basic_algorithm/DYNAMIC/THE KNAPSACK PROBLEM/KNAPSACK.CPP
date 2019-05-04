#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("KNAPSACK.INP", ios::in);
ofstream bfile("KNAPSACK.OUT", ios::out);

int N, S;
int W[2001], V[2001];
int F[2001][2001];


void Read();
void Write();

void Try() {
    for (int i = 1; i <= N; ++i)
        F[0][i] = 0;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= S; ++j) {
            F[i][j] = F[i - 1][j];

            if (j >= W[i] && F[i][j] < F[i - 1][j - W[i]] + V[i])
                F[i][j] = F[i - 1][j - W[i]] + V[i];
        }
}

int main() {
    Read();
    Try();
    Write();
    return 0;
}

void Read() {
    afile >> N >> S;
    for (int i = 1; i <= N; ++i)
        afile >> W[i] >> V[i];
    afile.close();
}

void Write() {
    bfile << F[N][S] << endl;
    while (N != 0) {
        if (F[N][S] != F[N - 1][S]) {
            bfile << N << '\t';
            S = S - W[N];
        }
        N--;
    }
    bfile.close();
}
