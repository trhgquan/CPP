#include <iostream>
#include <fstream>
// Required for QuickSort
#include <cstdlib>
#include <ctime>

using namespace std;

ifstream afile("SEARCH.INP", ios::in);
ofstream bfile("BINARY.OUT", ios::out);

int N, K;
int A[1001];
bool found;

void Read() {
    afile >> N >> K;
    for (int i = 1; i <= N; ++i)
        afile >> A[i];
    afile.close();
}

void Quick_sort(int L, int H) {
    int Pivot;

    if (L >= H) return;

    // Generate random
    srand(time(NULL));
    int random = L + rand() % (H - L);

    Pivot = A[random];
    int i = L; int j = H;

    do {
        while (A[i] < Pivot) i++;
        while (A[j] > Pivot) j--;

        if (i <= j) {
            swap(A[i], A[j]);
            i++; j--;
        }
    } while (i <= j);

    Quick_sort(L, j); Quick_sort(i, H);
}

void Binary_search() {
    int inf = 1; int sup = N;
    int median;

    while (inf <= sup) {
        median = (inf + sup) / 2;
        if (A[median] == K) {
            bfile << "Element found!";
            return;
        }

        if (A[median] < K) inf = median + 1;
        else sup = median - 1;
    }
    bfile << "Element not exist!";
}

void Write() {
    bfile.close();
}

int main() {
    Read();
    // To use Binary Search, first the array must be sorted.
    // Use Quick Sort from SORTING\QUICK_SORT
    Quick_sort(1, N);
    Binary_search();
    Write();
    return 0;
}
