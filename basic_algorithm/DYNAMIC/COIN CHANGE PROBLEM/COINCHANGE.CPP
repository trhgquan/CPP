// THIS SOLUTION GIVE MINIMUM
// STEPS TO CHANGE M TO COINS
#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("COINCHANGE.INP", ios::in);
ofstream bfile("COINCHANGE.OUT", ios::out);

int N, M;
int A[10001], MIN[10001]; // A FOR COINS, MIN FOR RESULT.

void Read() {
    afile >> N >> M;
    for (int i = 1; i <= N; ++i)
        afile >> A[i];
    afile.close();
}

void Try() {
    MIN[0] = 0;

    for (int i = 1; i <= M; ++i)
        MIN[i] = M + 1;

    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            if (A[j] <= i && MIN[i - A[j]] + 1 < MIN[i])
                MIN[i] = MIN[i - A[j]] + 1;

    bfile << MIN[M];
    bfile.close();
}

int main() {
    Read();
    Try();
    return 0;
}
