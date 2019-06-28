#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("SORT.INP", ios::in);
ofstream bfile("MERGETOP.OUT", ios::out);

int N;
int K[1001], T[1001];

void Read() {
    afile >> N;
    for (int i = 1; i <= N; ++i)
        afile >> K[i];
    afile.close();
}

void Write() {
    for (int i = 1; i <= N; ++i)
        bfile << K[i] << '\t';
    bfile.close();
}

// Top-down implementation
void TopDownMergeSort(int *A, int *B);
void TopDownSplitMerge(int *B, int *A, int aBegin, int aEnd);
void TopDownMerge(int *A, int *B, int aBegin, int aMiddle, int aEnd);
void CopyArray(int *B, int *A, int aStart, int aEnd);

int main() {
    Read();
    TopDownMergeSort(K, T);
    Write();
    return 0;
}

void TopDownMergeSort(int *A, int *B) {
    CopyArray(B, A, 1, N + 1);
    TopDownSplitMerge(B, A, 1, N + 1);
}

void TopDownSplitMerge(int *B, int *A, int aBegin, int aEnd) {
    if (aEnd - aBegin < 2) return;

    int aMiddle = (aEnd + aBegin) / 2;

    TopDownSplitMerge(A, B, aBegin, aMiddle);
    TopDownSplitMerge(A, B, aMiddle, aEnd);

    TopDownMerge(B, A, aBegin, aMiddle, aEnd);
}

void TopDownMerge(int *A, int *B, int aBegin, int aMiddle, int aEnd) {
    int i = aBegin; int j = aMiddle;

    for (int k = aBegin; k < aEnd; k++) {
        if (i < aMiddle && (j >= aEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
    }
}

// Copy array A to B
void CopyArray(int *B, int *A, int aStart, int aEnd) {
    for (int i = aStart; i < aEnd; ++i)
        B[i] = A[i];
}
