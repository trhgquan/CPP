#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("SHELL_SORT.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

void Shell_sort() {
    int h, j, tmp;

    h = N / 2;

    while (h != 0) {
        for (int i = h + 1; i <= N; ++i) {
            tmp = K[i]; j = i - h;

            while (j > 0 && K[j] > tmp) {
                K[j + h] = K[j];
                j = j - h;
            }

            K[j + h] = tmp;
        }
        h = h / 2;
    }
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Shell_sort();
    Print();
    return 0;
}
