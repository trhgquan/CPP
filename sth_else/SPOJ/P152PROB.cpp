/**
 * P152PROB - https://www.spoj.com/PTIT/problems/P152PROB
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    vector<int>H; for (int i = 1; i <= N; ++i) {int u; cin >> u; H.push_back(u);}

    // Knowing how to use STL algorithms is an advantage.
    sort(H.begin(), H.end());

    int res = 0;
    for (int i = 0; i < N - 1; ++i)
        if (H[i + 1] - H[i] > K) ++res;
    cout << res + 1;
    return 0;
}
