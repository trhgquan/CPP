// LIS for Longest Increasing Subsequence
// geeksforgeeks solution.

#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("LIS.inp", ios::in);
ofstream bfile("LIS-1.out", ios::out);

// A for Array, L for LIS, T for Trace
int A[101], L[101], T[101];
int n, m;

void read() {
    afile >> n;

    for (int i = 1; i <= n; ++i)
        afile >> A[i];
}

void LIS () {
    m = 1;

    for (int i = 1; i <= n; ++i) {
        L[i] = 1;
    }


    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            if (A[i] > A[j] && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;

                if (L[i] > m) {
                    m = L[i];
                    T[n + 1] = i;
                }


                T[i] = j;
            }
}

void write() {
    bfile << m << endl;

    int i = T[n + 1];

    while (i != 0) {
        bfile << A[i] << ' ';
        i = T[i];
    }
}

int main() {
    read();

    LIS();

    write();

    afile.close();
    bfile.close();

    return 0;
}
