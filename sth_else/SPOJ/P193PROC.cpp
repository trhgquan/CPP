/**
 * P193PROC - https://www.spoj.com/PTIT/problems/P193PROC
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

string pS(string a) {
    string res = "";
    int x = 0;
    for (unsigned i = 0; i < a.size(); ++i)
        x += a[i] - '0';

    while (x > 0) {
        res += x % 10 + '0';
        x /= 10;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input; cin >> input;
    int count = 0;
    while (input.size() > 1) {
        input = pS(input);
        ++count;
    }
    cout << count;
    return 0;
}
