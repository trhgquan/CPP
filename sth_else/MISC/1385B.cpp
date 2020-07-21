/**
 * 1385B - https://codeforces.com/problemset/problem/1385/B
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        unordered_set<int>unique;
        vector<int>ans;
        for (int i = 1; i <= 2 * N; ++i) {
            int u; cin >> u;
            if (unique.find(u) == unique.end()) {
                unique.insert(u);
                ans.push_back(u);
            }
        }

        for (int i = 0; i < (int)ans.size(); ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
