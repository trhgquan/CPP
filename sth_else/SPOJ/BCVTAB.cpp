/**
 * BCVTAB - https://www.spoj.com/PTIT/problems/BCVTAB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

void addZeros(string& a, int n) {
    for (int i = 1; i <= n; ++i) a.insert(a.begin(), '0');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    string a, b; cin >> a >> b;
    if (a.size() > b.size()) addZeros(b, a.size() - b.size());
    if (b.size() > a.size()) addZeros(a, b.size() - a.size());

    int temp = 0; string res;
    for (int i = a.size() - 1; i >= 0; --i) {
        int sum = a[i] - 48 + b[i] - 48 + temp;
        temp = sum / 10;
        res.insert(res.begin(), (sum % 10) + 48);
    }
    if (temp != 0) res.insert(res.begin(), temp + 48);
    cout << res;

    return 0;
}
