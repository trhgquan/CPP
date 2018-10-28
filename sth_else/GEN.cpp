#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Tru (string a, int b)
{
    string s = "";

    while (b != 0)
    {
        s = char(b % 10 + '0') + s;
        b /= 10;
    }

    while (a.length() > s.length())
        s = '0' + s;

    int nho = 0;
    string k;

    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] - (s[i] + nho) >= 0)
        {
            k = char(a[i] - (s[i] + nho) + '0') + k;
            nho = 0;
        }
        else
        {
            k = char(a[i] + 10 - (s[i] + nho) + '0') + k;
            nho = 1;
        }
    }

    return k;
}

long KiemTra (string a)
{
    string s = "";
    long sum = 0;

    for (int i = 0; i < a.length(); i++)
        sum += a[i] - '0';

    return sum;
}

int main() {
    std::ifstream afile("GEN.inp", std::ios::in);
    std::ofstream bfile("GEN.out", std::ios::out);

    long T;
    int sum, dd, f;
    string M, v;

    afile >> T;
    for (long i = 0; i < T; i++)
    {
        afile >> M;
        dd = 1;
        f = M.length() * 9;

        while (f >= 1)
        {
            v = Tru(M, f);

            if (KiemTra(v) == f)
            {
                while (v[0] == '0')
                    v.erase(v.begin());

                bfile << v << '\n';
                dd = 0;

                break;
            }
            f--;
        }

        if (dd == 1)
            bfile << 0 << '\n';
    }

    afile.close();
    bfile.close();
    return 0;
}
