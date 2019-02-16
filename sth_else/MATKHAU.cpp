#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream afile("MATKHAU.inp", ios::in);
ofstream bfile("MATKHAU.out", ios::out);

string password;
int total;

bool hasUppercase (int f, int t);
bool hasNormal (int f, int t);
bool hasNumber (int f, int t);
bool isOK (int f, int t);

int main() {
    afile >> password;

    for (unsigned int i = 1; i <= password.length() - 5; ++i) {
        for (unsigned int j = i + 5; j <= password.length(); ++j)
            if (isOK(i, j))
                ++total;
    }

    bfile << "Safe passwords: " << total << endl;

    afile.close();
    bfile.close();

    return 0;
}

bool isOK (int f, int t) {
    return (hasNumber(f, t) && hasUppercase(f, t) && hasNormal(f, t));
}

bool hasUppercase (int f, int t) {
    for (int i = f; i <= t; ++i)
        if (password[i] <= 'Z' && password[i] >= 'A') {
            return true;
            break;
        }
    return false;
}

bool hasNormal (int f, int t) {
    for (int i = f; i <= t; ++i)
        if (password[i] <= 'z' && password[i] >= 'a') {
            return true;
            break;
        }
    return false;
}

bool hasNumber (int f, int t) {
    for (int i = f; i <= t; ++i)
        if (password[i] <= '9' && password[i] >= '0') {
            return true;
            break;
        }
    return false;
}
