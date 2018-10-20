#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// CREATE A REVERSE STRING.
string reverse (string a)
{
    int i;
    string b;
    // LAST CHAR OF THE ORIGINAL STRING IS THE FIRST NEW STRING CHAR
    b += a[a.length() - 1];
    // OTHER CHARS REMAIN.
    for (i = 0; i <= a.length() - 2; i++)
        b += a[i];
    return b;
}

// now we create all available strings.
string recursion(string a, int time, int k)
{
    string b;
    // loops to string.length();
    if (time >= 1)
        b = reverse(a);
        // the string we need.
        if (time == k)
            // return that string.
            return b;
        return recursion(b, time - 1, k);
    return "-1";
}

int main() {
    std::ifstream afile("timxau.inp", std::ios::in);
    std::ofstream bfile("timxau.out", std::ios::out);

    int k;
    string s, m;

    afile >> k;
    afile >> s;

    bfile << recursion(s, s.length(), k);

    afile.close();
    bfile.close();
    return 0;
}
