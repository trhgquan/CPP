// BSE Binary String Enumeration
// Backtracking algorithm
#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("BSE.INP", ios::in);
ofstream bfile("BSE.OUT", ios::out);

int n;
int x[101];

void Read() {
    afile >> n;
    afile.close();
}

void Write() {
    for (int i = 1; i <= n; ++i)
        bfile << x[i];
    bfile << endl;
}

void Try(int i) {
    for (int j = 0; j <= 1; ++j) {
        x[i] = j;

        if (i == n) Write();
        else Try(i + 1);
    }
}

int main() {
    Read();
    Try(1);
    return 0;
}
