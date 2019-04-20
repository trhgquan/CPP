// A STRING TO MANY STRING WITH ITS CHARACTERS
#include <iostream>
#include <string>
#include <fstream>

int n;
char a[101], r[101];
bool b[101];

std::string s;

std::ifstream afile("STRINGBCKTRACK.INP", std::ios::in);
std::ofstream bfile("STRINGBCKTRACK.OUT", std::ios::out);

void print() {
    for (int j = 1; j <= s.length(); ++j)
        bfile << r[j];
    bfile << std::endl;
}

void backtrack (int i) {
    if (i > s.length())
        print();

    for (int j = 1; j <= s.length(); ++j)
        if (!b[j]) {
            b[j] = true;
            r[i] = a[j];
            backtrack(i + 1);
            b[j] = false;
        }
}

int main() {
    while (!afile.eof()) {
        afile >> s;

        for (int i = 0; i < s.length(); ++i) {
            a[i + 1] = s[i];
            b[i] = false;
        }


        backtrack(1);
    }

    afile.close();
    bfile.close();
    return 0;
}


