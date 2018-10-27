#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Ham numFromNumber, tra ve cac chu so tu mot so
 * su dung kieu du lieu vector de return.
 * @param  int n
 * @return std::vector<int>
 */
std::vector<int> numFromNumber (int n)
{
    std::vector<int> a;
    while (n > 0)
    {
        a.push_back(n % 10);
        n /= 10;
    }
    return a;
}

int main() {
    std::ifstream afile("GEN.inp", std::ios::in);
    std::ofstream bfile("GEN.out", std::ios::out);

    int T;
    afile >> T;

    int M[T];

    for (int i = 0; i < T; i++)
        afile >> M[i];

    for (int i = 0; i < T; i++)
    {
        int sum = 0, num = 0;
        // Vet can tu 0.
        for (int j = 0; j < M[i]; j++) {
            sum = j;
            // Tim cac chu so cua j.
            std::vector<int> number = numFromNumber(j);
            // Tinh tong so j voi cac chu so j[k] cua no
            for (int k = 0; k < number.size(); k++)
                sum += number[k];
            if (sum == M[i] && num == 0)
                num = j;
        }
        bfile << num << '\n';
    }

    afile.close();
    bfile.close();
    return 0;
}
