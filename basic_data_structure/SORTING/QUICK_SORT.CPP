#include <iostream>
#include <fstream>
// For srand() and rand()
#include <cstdlib>
#include <ctime>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("QUICK_SORT.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

void Quick_sort(int L, int H) {
    int Pivot;

    if (L >= H) return;

    // Generate random
    srand(time(NULL));
    int random = L + rand() % (H - L);

    Pivot = K[random];
    int i = L; int j = H;

    do {
        while (K[i] < Pivot) i++;
        while (K[j] > Pivot) j--;

        if (i <= j) {
            swap(K[i], K[j]);
            i++; j--;
        }
    } while (i <= j);

    Quick_sort(L, j); Quick_sort(i, H);
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Quick_sort(1, N);
    Print();
    return 0;
}
