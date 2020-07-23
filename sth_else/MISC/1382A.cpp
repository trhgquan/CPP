/**
 * 1382A - https://codeforces.com/contest/1382/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int>a; for (int i = 1; i <= n; ++i) {int u; cin >> u; a.push_back(u);}
        vector<int>b; for (int i = 1; i <= m; ++i) {int u; cin >> u; b.push_back(u);}
        sort(a.begin(), a.end());

        bool found = 0;
        int ans = -1;
        for (int i = 1; i <= m; ++i) {
            if (binary_search(a.begin(), a.end(), b[i - 1])) {
                found = 1;
                ans = b[i - 1];
                break;
            }
        }

        if (!found) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << 1 << ' ' << ans << endl;
        }
    }

    return 0;
}
