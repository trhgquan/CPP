#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("SELECTION_SORT.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

void Selection_sort() {
    int jMin, temp;

    for (int i = 1; i <= N - 1; ++i) {
        jMin = i;

        for (int j = i + 1; j <= N; ++j)
            if (K[j] < K[jMin]) jMin = j;

        if (jMin != i) swap(K[i], K[jMin]);

    }
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Selection_sort();
    Print();
    return 0;
}
