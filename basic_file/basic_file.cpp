#include <fstream>
#include <iostream>

using namespace std;

int exponentiation (int a, int b)
{
    int i,c;

    c = 1;

    for (i = 1; i <= b; i++) {
        c *= a;
    }
    return c;
}

int main() {
    ifstream infile("basic_file_input.inp");
    ofstream outfile("basic_file_output.out");

    int a,b;

    while (infile >> a >> b) {
        outfile << exponentiation(a,b) << "\n";
    }
    return 0;
}
