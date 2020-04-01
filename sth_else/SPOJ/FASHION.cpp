/**
 * FASHION - https://www.spoj.com/problems/FASHION
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int>a; for (int i = 1; i <= N; ++i) {int u; cin >> u; a.push_back(u);}
        vector<int>b; for (int i = 1; i <= N; ++i) {int u; cin >> u; b.push_back(u);}

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int res = 0;
        for (int i = 0; i < N; ++i) res += a[i] * b[i];
        cout << res << endl;
    }

    return 0;
}
