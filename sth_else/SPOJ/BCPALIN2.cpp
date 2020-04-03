/**
 * BCPALIN2 - https://www.spoj.com/PTIT/problems/BCPALIN2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int res = 0;
    vector<vector<int>>L(s.size(), vector<int>(s.size()));
    for (unsigned i = 0; i < s.size(); ++i) L[i][i] = 1;

    for (unsigned k = 2; k <= s.size(); ++k) {
        for (unsigned i = 0; i < s.size() - k + 1; ++i) {
            unsigned j = i + k - 1;

            if (s[i] == s[j] && k == 2) L[i][j] = 2;
            else if (s[i] == s[j]) L[i][j] = L[i + 1][j - 1] + 2;
            else L[i][j] = max(L[i + 1][j], L[i][j - 1]);

            if (L[i][j] > res) res = L[i][j];
        }
    }
    cout << res;
    return 0;
}
