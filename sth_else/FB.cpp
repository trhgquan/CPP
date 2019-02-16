#include <iostream>
#include <fstream>

using namespace std;

ifstream afile("FB.inp", ios::in);
ofstream bfile("FB.out", ios::out);

int n;

long long int fibonacci (int n) {
    if (n == 1 || n == 2)
        return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

void Try() {

    afile >> n;

    // Fibonacci (25) = 75025 > 60000
    int topBorder = 25;

    while (n >= 1) {
        for (int i = 1; i <= topBorder; ++i) {
            if (fibonacci(i) > n) {

                int j = fibonacci(i - 1);

                bfile << j;

                topBorder = i - 1;

                n = n - j;

                if (n >= 1)
                    bfile << " + ";

                break;
            }
        }
    }

    bfile << endl;
}

int main() {

    while (!afile.eof())
        Try();

    bfile.close();

   return 0;
}
