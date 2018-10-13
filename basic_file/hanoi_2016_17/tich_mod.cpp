#include <iostream>
#include <fstream>

using namespace std;

// using recursion
int number (int from, int to)
{
    if (from <= to)
        return to * number(from, to - 1);
    return 1;
}

int main() {
    std::ifstream afile("tich_mod.inp", std::ios::in);
    std::ofstream bfile("tich_mod.out", std::ios::out);

    int a, b, c;

    afile >> a >> b >> c;

    bfile << number(a,b) % c;

    afile.close();
    bfile.close();
    return 0;
}
