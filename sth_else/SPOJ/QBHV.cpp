// PROBLEM:
// https://vn.spoj.com/problems/QBHV/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s;
    string r;
    int c = 0;

    getline(cin, s);
    // next_permutation requires sorted array
    sort(s.begin(), s.end());

    do {
        r += s + '\n'; c++;
    } while (next_permutation(s.begin(), s.end()));
    cout << c << endl;
    cout << r;

    return 0;
}
