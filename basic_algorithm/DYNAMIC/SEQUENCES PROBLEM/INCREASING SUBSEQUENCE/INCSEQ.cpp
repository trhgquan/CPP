// LARGEST INCREASING SEQUENCE PROBLEM
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream afile("INCSEQ.inp", ios::in);
ofstream bfile("INCSEQ.out", ios::out);

int n;
int A[10001], L[10001], T[10001];

void read() {
    afile >> n;
    for (int i = 1; i <= n; ++i)
        afile >> A[i];
}

void Try (){
    A[0] = -INT_MAX;
    A[n + 1] = INT_MAX;

    L[n + 1] = 1;
    int jmax;

    for (int i = n; i >= 0; i--) {
        jmax = n + 1;

        for (int j = i + 1; j <= n + 1; j++)
            if (A[j] > A[i] && L[j] > L[jmax])
                jmax = j;

        L[i] = L[jmax] + 1;
        T[i] = jmax;
    }

}

void print() {
    bfile << L[0] - 2 << endl;
    int i = T[0];

    while (i != n + 1) {
        bfile << A[i] << '\t';
        i = T[i];
    }
}

int main() {
    read();

    Try();

    print();


    afile.close();
    bfile.close();
    return 0;
}
