/**
 * ADASTAIR - https://www.codechef.com/problems/ADASTAIR
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int N, K, S;
    while (T--) {
        cin >> N >> K;
        S = 0;
        vector<int> a; a.push_back(0);
        for (int i = 1; i <= N; ++i) {
            int u; cin >> u; a.push_back(u);
        }
        for (int i = 1; i <= N; ++i)
            if (a[i] - a[i - 1] > K) {
                S += (a[i] - a[i - 1]) / K;
                if ((a[i] - a[i - 1]) % K == 0) S--;
            }

        cout << S << endl;
    }
    return 0;
}
