#include "iostream"
#include "fstream"

using namespace std;

// find the max element in an array
int findMax (int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main() {
    std::ifstream afile("longest_sub.inp", std::ios::in);
    std::ofstream bfile("longest_sub.out", std::ios::out);

    int m;
    afile >> m;

    int A[m], L[m];
    for (int i = 0; i < m; i++) {
        afile >> A[i];
    }
    // general:
    L[0] = 1;
    // By L[0] = 1, which told us A[0] is checked, we start from A[1].
    for (int i = 1; i < m; i++) {
        int LMax = 0;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                if (L[j] > LMax) {
                    LMax = L[j];
                }
            }
            L[i] = LMax + 1;
        }

    }

    // write the results to a file.
    bfile << "A : ";
    for (int i = 0; i < m; i++)
        bfile << A[i] << '\t';
    bfile << '\n';
    bfile << "L : ";
    for (int i = 0; i < m; i++)
        bfile << L[i] << '\t';
    int max = findMax(L,m);
    if (max > 1)
        bfile << '\n' << "Maximum: " << findMax(L, m);
    else
        bfile << '\n' << -1;

    afile.close();
    bfile.close();
    return 0;
}
