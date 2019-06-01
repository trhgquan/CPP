#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("INSERTION_SORT.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

void Insertion_sort() {
    int tmp;

    for (int i = 2; i <= N; ++i) {
        tmp = K[i];

        int j = i - 1;

        while (j > 0 && tmp < K[j]) {
            K[j + 1] = K[j];
            j--;
        }
        K[j + 1] = tmp;
    }
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Insertion_sort();
    Print();
    return 0;
}
