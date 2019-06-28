#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("MERGEBOT.OUT", ios::out);

int N;
int K[1001], T[1001];

void BottomUpMergeSort(int *A, int *B, int N);
void BottomUpMerge(int *A, int *B, int aLeft, int aRight, int aEnd);
void CopyArray(int *B, int *A, int N);

void Read() {
    afile >> N;
    for (int i = 0; i < N; ++i)
        afile >> K[i];
    afile.close();
}

void Write() {
    for (int i = 0; i < N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

int main() {
    Read();
    BottomUpMergeSort(K, T, N);
    Write();
    return 0;
}

void BottomUpMergeSort(int *A, int *B, int N) {
    for (int width = 1; width < N; width = 2 * width) {
        for (int i = 0; i < N; i = i + 2 * width)
            BottomUpMerge(A, B, i, min(i + width, N), min(i + 2 * width, N));

        CopyArray(B, A, N);
    }
}

void BottomUpMerge(int *A, int *B, int aLeft, int aRight, int aEnd) {
    int i = aLeft; int j = aRight;

    for (int k = aLeft; k < aEnd; ++k) {
        if (i < aRight && (j >= aEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
    }
}

// Copy array (B to A)
void CopyArray(int *B, int *A, int N) {
    for (int i = 0; i < N; ++i)
        A[i] = B[i];
}
