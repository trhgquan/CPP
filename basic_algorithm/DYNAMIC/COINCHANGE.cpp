#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream afile("COINCHANGE.inp", ios::in);
ofstream bfile("COINCHANGE.out", ios::out);

int n;
int S, t[21];

void read() {
    afile >> n >> S;

    for (int i = 0; i < n; i++)
        afile >> t[i];
}

int currencyChange(int n, int S, int *t) {
    int table[S + 1];

    table[0] = 0;

    for (int i = 1; i <= S; i++)
        table[i] = INT_MAX;

    for (int i = 1; i <= S; i++) {
        for (int j = 0; j < n; j++)
            if (t[j] <= i) {
                int sub_table = table[i - t[j]];

                if (sub_table != INT_MAX && sub_table + 1 < table[i])
                    table[i] = sub_table + 1;
            }
    }
    return table[S];
}

int main() {
    read();
    bfile << currencyChange(n, S, t);

    afile.close();
    bfile.close();
    return 0;
}
