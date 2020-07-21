#include <iostream>
#include <fstream>

// For srand() and rand()
#include <cstdlib>
#include <ctime>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("QUICK.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;

    for (int i = 1; i <= N; ++i)
        afile >> K[i];

    afile.close();
}

// This method is mentioned in the DSAP Textbook - Minh-Hoang Le (PhD).
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

// This method is mentioned in GeeksforGeeks,
// which doesn't require random pivot.
int partition(int low, int high) {
    int pivot = K[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (K[j] < pivot) {
            ++i;
            swap(K[i], K[j]);
        }
    }
    swap(K[i + 1], K[high]);
    return i + 1;
}

void quickSortDnC(int low, int high) {
    if (low >= high) return;

    int part = partition(low, high);
    quickSortDnC(low, part - 1);
    quickSortDnC(part + 1, high);
}

void Print() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();

    // Choose 1 from 2 function below.

    // Quick_sort(1, N);
    // quickSortDnC(1, N);

    Print();
    return 0;
}
