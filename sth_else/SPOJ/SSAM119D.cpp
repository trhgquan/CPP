/**
 * SSAM119D - https://www.spoj.com/PTIT/problems/SSAM119D
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        vector<vector<int>>table(s.size() + 1, vector<int>(s.size() + 1, 0));

        unsigned res = 1;

        for (unsigned i = 0; i < s.size(); ++i) table[i][i] = 1;

        for (unsigned i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = 1;
                res = 2;
            }
        }

        for (unsigned k = 3; k <= s.size(); ++k) {
            for (unsigned i = 0; i < s.size() - k + 1; ++i) {
                unsigned j = i + k - 1;
                if (table[i + 1][j - 1] && s[i] == s[j]) {
                    table[i][j] = 1;
                    if (k > res) res = k;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
