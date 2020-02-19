/**
 * CASH - https://codechef.com/problems/CASH
 * Codechef February Challenge 2020
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        int S = 0;
        for (int i = 1; i <= N; ++i){
            int u; cin >> u;
            if (u % K != 0)
                S = (S + u) % K;
        }
        cout << S << endl;
    }
    return 0;
}
