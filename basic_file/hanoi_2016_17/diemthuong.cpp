#include <iostream>
#include <fstream>

using namespace std;

// simple finding max element algorithm
int max (int a[], int top)
{
    int i, max;
    max = a[0];
    for (i = 1; i < top; i++)
        if (a[i] > max)
            max = a[i];
    std::cout << max << '\n';
    return max;
}

int main() {
    std::ifstream afile("diemthuong.inp", std::ios::in);
    std::ofstream bfile("diemthuong.out", std::ios::out);

    short int n, k, count = 0;

    afile >> n;

    int a[n];

    while (count <= n && afile >> a[count])
        count++;

    for (count = 1; count <= n; count++)
        bfile << max(a, count) << " ";

    afile.close();
    bfile.close();

    return 0;
}
