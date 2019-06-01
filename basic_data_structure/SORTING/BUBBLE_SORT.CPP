#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("BUBBLE_SORT.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

void Bubble_sort() {
    for (int i = 2; i <= N; ++i)
        for (int j = N; j >= i; --j)
            if (K[j] < K[j - 1]) swap(K[j], K[j - 1]);
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Bubble_sort();
    Print();
    return 0;
}
