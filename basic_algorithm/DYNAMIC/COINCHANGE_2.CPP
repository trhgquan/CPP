#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream afile("COINCHANGE.INP", ios::in);
ofstream bfile("COINCHANGE_2.OUT", ios::out);

int N, M;
int A[10001], L[10001][10001];

void Read() {
    afile >> N >> M;
    for (int i = 1; i <= N; ++i)
        afile >> A[i];
    afile.close();
}

void Try() {
    for (int i = 0; i <= N; ++i) L[i][0] = 0;
    for (int j = 1; j <= M; ++j) L[0][j] = INT_MAX;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            L[i][j] = L[i - 1][j];
            if (A[i] <= j)
                L[i][j] = min(L[i][j - A[i]] + 1, L[i - 1][j]);
        }
}

void Trace(int i, int j) {
    if (i == 0) return;
    if (j == 0) return;

    if (j >= A[i]) {
        if (L[i][j] == 1 + L[i][j - A[i]]) {
            Trace(i, j - A[i]);
            bfile << "Coin type " << A[i] << " : 1" << endl;
        } else Trace(i - 1, j);
    } else Trace(i - 1, j);
}

void Write() {
    if (L[N][M] == INT_MAX)
        bfile << "Cannot make changes" << endl;
    else {
        bfile << L[N][M] << endl;
        Trace(N, M);
    }
    bfile.close();
}

int main() {
    Read();
    Try();
    Write();
    return 0;
}
