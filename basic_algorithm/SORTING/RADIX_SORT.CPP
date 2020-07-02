#include <iostream>
#include <fstream>

#define DIGITS 10

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("RADIX.OUT", ios::out);

int N;
int K[1001];

void Read() {
    afile >> N;
    for (int i = 0; i < N; ++i)
        afile >> K[i];
    afile.close();
}

int getMax (int *A) {
    int m = A[0];
    for (int i = 1; i < N; ++i) {
        if (K[i] >= m)
            m = K[i];
    }
    return m;
}

// countSort aka Distribution Counting
void countSort(int *A, int exp) {
    int output[N];
    // Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
    int count[DIGITS] = {0};

    for (int i = 0; i < N; ++i)
        count[(A[i] / exp) % 10]++;

    for (int i = 1; i < DIGITS; ++i)
        count[i] += count[i - 1];

    for (int i = N - 1; i >= 0; --i) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < N; ++i)
        A[i] = output[i];
}

void Radix_sort(int *A) {
    int max = getMax(A);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(A, exp);
}

void Write() {
    for (int i = 0; i < N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    Radix_sort(K);
    Write();
    return 0;
}
