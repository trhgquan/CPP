// geeksforgeeks.org/longest-common-subsequence-dp-4/
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

#define CHRMAX 250000

using namespace std;

ifstream afile("LCS.inp", ios::in);
ofstream bfile("LCS_DP4.out", ios::out);

char a[CHRMAX], b[CHRMAX];


void read();
int Longest_substring(char x[], char y[], int m, int n);

int main() {
    read();

    bfile << "Longest substring: " << Longest_substring(a, b, strlen(a), strlen(b));

    afile.close();
    bfile.close();
    return 0;
}

void read() {
    afile >> a;
    afile >> b;
}

int Longest_substring (char x[], char y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + Longest_substring(x, y, m - 1, n - 1);
    else
        return max(Longest_substring(x, y, m, n - 1), Longest_substring(x, y, m - 1, n));
}
