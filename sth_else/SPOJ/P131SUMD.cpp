/**
 * P131SUMD - https://www.spoj.com/PTIT/problems/P131SUMD
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int toNum(string a) {
    int res = 0;
    for (unsigned i = 0; i < a.size(); ++i) res = res * 10 + (a[i] - 48);
    return res;
}

string toMin(string a) {
    for (unsigned i = 0; i < a.size(); ++i)
        if (a[i] == '6') a[i] = '5';
    return a;
}

string toMax(string a) {
    for (unsigned i = 0; i < a.size(); ++i)
        if (a[i] == '5') a[i] = '6';
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    a = toMin(a); b = toMin(b); cout << toNum(a) + toNum(b) << ' ';
    a = toMax(a); b = toMax(b); cout << toNum(a) + toNum(b);
    return 0;
}
