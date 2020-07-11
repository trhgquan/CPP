/**
 * 1303A - https://codeforces.com/problemset/problem/1303/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int onePos = -1;
        int res = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1') {
                if (onePos != -1)
                    res += i - onePos - 1;
                onePos = i;
            }
        }
        cout << res << endl;
    }

    return 0;
}
