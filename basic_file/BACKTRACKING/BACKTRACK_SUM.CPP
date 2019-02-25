// EXAMPLE: 1 3
// ONE INPUT, 3 ITEMS MAKE RESULT
// LIST ITEMS..

#include <iostream>
#include <fstream>

std::ifstream afile("BACKTRACK_SUM.INP", std::ios::in);
std::ofstream bfile("BACKTRACK_SUM.OUT", std::ios::out);

int sum, m_sum;
int DD[10001];
int B[10001];

void print(int i) {
    for (int j = 1; j <= i; ++j) {

        bfile << B[j];
        if (j < i)
            bfile << " + ";
    }

    bfile << " = " << sum << std::endl;
}

void Try (int i) {
    for (int j = B[i - 1]; j <= (sum - DD[i - 1]); ++j) {

        B[i] = j;
        DD[i] = DD[i - 1] + j;

        if (DD[i] == sum && i == m_sum)
            print(i);
        else Try(i + 1);
    }
}

int main() {
    int n, m;

    afile >> n >> m_sum;

    while (n--) {
        afile >> sum;

        B[0] = 1;

        DD[0] = 0;

        Try(1);
    }

    bfile.close();
    afile.close();
    return 0;
}
