/**
 * POPGATES - https://www.codechef.com/LTIME81B/problems/POPGATES
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<int>C;
        for (int i = 1; i <= N; ++i) {
            char u; cin >> u;
            if (u == 'H') C.push_back(1);
            else C.push_back(0);
        }

        for (int i = 0; i < K; ++i) {
            if (C[C.size() - i - 1] == 1) {
                for (int j = C.size() - i; j >= 0; --j)
                    if (C[j] == 1) C[j] = 0;
                    else C[j] = 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < N - K; ++i)
            ans += C[i];
        cout << ans << endl;
    }
    return 0;
}
