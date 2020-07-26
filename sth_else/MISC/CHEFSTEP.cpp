/**
 * CHEFSTEP - https://www.codechef.com/LTIME86B/problems/CHEFSTEP
 * Codechef July Lunchtime 2020 - Division 2
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
        int N, K; cin >> N >> K;
        std::vector<int> v; for (int i = 1; i <= N; ++i) {int u; cin >> u; v.push_back(u);}
        for (int i = 0; i < N; ++i)
            cout << ((v[i] % K == 0 && v[i] >= K) ? 1 : 0);
        cout << endl;
    }
    return 0;
}
