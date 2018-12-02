#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("LCS.inp", ios::in);
ofstream bfile("LCS_DP29.out", ios::out);

string x, y;
void read();
int Longest_substring(int i, int j, int count);


int main() {
    read();

    int n, m;
    n = x.size();
    m = y.size();

    bfile << Longest_substring(n, m, 0) ;

    afile.close();
    bfile.close();
    return 0;
}

void read() {
    afile >> x;
    afile >> y;
}

int Longest_substring(int i, int j, int count)
{
    if (i == 0 || j == 0)
        return count;
    if (x[i - 1] == y[j - 1]) {
        count = Longest_substring(i - 1, j - 1, count + 1);
    }
    count = max(count, max(Longest_substring(i, j - 1, 0), Longest_substring(i - 1, j, 0)));
    return count;
}
