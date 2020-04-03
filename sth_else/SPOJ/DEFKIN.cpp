/**
 * DEFKIN - https://www.spoj.com/problems/DEFKIN
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int w, h, n; cin >> w >> h >> n;

        if (n == 0) cout << w * h << endl;
        else {
            vector<int>tx, ty;
            for (int i = 1; i <= n; ++i) {
                int x, y; cin >> x >> y;
                tx.push_back(x); ty.push_back(y);
            }

            sort(tx.begin(), tx.end());
            sort(ty.begin(), ty.end());

            int max_xSpace = tx[0] - 1, max_ySpace = ty[0] - 1;
            for (int i = 1; i < n; ++i) {
                max_xSpace = max(max_xSpace, tx[i] - tx[i - 1] - 1);
                max_ySpace = max(max_ySpace, ty[i] - ty[i - 1] - 1);
            }

            max_xSpace = max(max_xSpace, w - tx[n - 1]);
            max_ySpace = max(max_ySpace, h - ty[n - 1]);

            cout << (max_xSpace) * (max_ySpace) << endl;
        }
    }


    return 0;
}
