#include <iostream>
#include <fstream>

#define M 1001

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("DISTRIBUTION_COUNTING.OUT", ios::out);

int N;
int K[M];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

void Distribution_counting() {
    int C[M], T[M];
    int V;

    for (V = 0; V <= M; ++V) C[V] = 0;
    for (int i = 1; i <= N; ++i) C[K[i]]++;
    for (V = 1; V <= M; ++V) C[V] = C[V - 1] + C[V];

    for (int i = N; i >= 1; --i) {
        V = K[i];
        T[C[V]] = K[i];
        C[V]--;
    }

    for (int i = 1; i <= N; ++i) K[i] = T[i];
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Distribution_counting();
    Print();
    return 0;
}
