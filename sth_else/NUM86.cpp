#include <iostream>
#include <fstream>

using namespace std;

int pow10[201];
ifstream afile("NUM86.inp", ios::in);
ofstream bfile("NUM86.out", ios::out);

void testcase() {
    int x;
    afile >> x;

    x *= 9;

    pow10[0] = 1;

    for (int i = 1; i <= 200; ++i)
        pow10[i] = pow10[i-1] * 10 % x;
    for (int nd = 1; nd <= 200; ++nd)
        for (int n8 = 0; n8 <= nd; ++n8)
            if((8*pow10[nd] - 2*pow10[nd-n8] - 6) % x == 0) {
                for(int i = 0; i < n8; ++i)
                    bfile << 8;
                for(int i = 0; i < nd - n8; ++i)
                    bfile << 6;
                bfile << '\n';
                return;
            }
    bfile << "-1\n";
}

int main() {
    int tc;
    afile >> tc;

    while (tc--)
        testcase();

    afile.close();
    bfile.close();
    return 0;
}
