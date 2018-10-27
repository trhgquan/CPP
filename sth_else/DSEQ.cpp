#include <iostream>
#include <fstream>

using namespace std;

int fromN (int a[], int m)
{
    int s = 0;
    for (int i = 0; i <= m; i++)
        s += a[i];
    return s;
}

int toN (int a[], int n, int m)
{
    int s = 0;
    for (int i = m; i < n ; i++)
        s += a[i];
    return s;
}

int main() {
    std::ifstream afile("DSEQ.inp", std::ios::in);
    std::ofstream bfile("DSEQ.out", std::ios::out);

    int n;
    afile >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        afile >> a[i];

    int calc = 0, max = 0, total = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            calc = abs(fromN(a, i) - toN(a, n, j));
            if (calc == max)
                total += 1;
            if (calc > max)
            {
                max = calc;
                total = 1;
            }
    }

    bfile << max << '\t' << total;

    afile.close();
    bfile.close();
    return 0;
}
