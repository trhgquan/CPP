/**
 * ALGOPRO4 - https://www.spoj.com/PTIT/problems/ALGOPRO4
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int power(int a) {
    if (a == 1) return 2;
    if (a == 2) return 4;
    return 1;
}

int main() {
    string num; cin >> num;
    while (num.size() % 3 != 0) num = '0' + num;
    for (unsigned i = 0; i < num.size() - 2; i += 3) {
        int convert = 0;
        for (int j = 0; j < 3; ++j)
            if (num[i + j] == '1') convert += power(2 - j);
        cout << convert;
    }
    return 0;
}
