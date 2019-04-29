// MSIS for Maximum Sum Increasing Subsequence
#include <iostream>
#include <fstream>

using namespace std;

// At here we use the LIS input, for example.
ifstream afile("INCSEQ.inp", ios::in);
ofstream bfile("MSIS.out", ios::out);

int MAX_SUM = 0;
int N;
// A for Array, S for Sum, L for Longest Increase Subsequence, T for Trace;
int A[101], S[101], L[101], T[101];

void read() {
    afile >> N;
    for (int i = 1; i <= N; ++i)
        afile >> A[i];
}

void LIS_SUM () {
    T[N + 1] = 0;

    for (int i = 1; i <= N; ++i) {
        L[i] = 1;
        S[i] = A[i];
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j < i; ++j)
            if (A[i] > A[j] && L[i] < L[j] + 1 && S[i] < S[j] + A[i]) {
                L[i] = L[j] + 1;
                S[i] = S[j] + A[i];
                T[i] = j;

                if (S[i] > MAX_SUM) {
                    MAX_SUM = S[i];
                    T[N + 1] = i;
                }
            }
    }
}

void write() {
    bfile << MAX_SUM << endl;
    bfile << "// Result = ";

    int i = T[N + 1];

    while (i != 0) {
        bfile << A[i];
        i = T[i];
        if (i > 0)
            bfile << " + ";
    }
}

int main() {
    read();

    LIS_SUM();

    write();

    afile.close();
    bfile.close();

    return 0;
}
