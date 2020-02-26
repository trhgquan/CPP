/**
 * UWCOI20A - https://codechef.com/problems/UWCOI20A
 * UWCOI2020 - online replay on Codechef
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int max = 0;
        for (int i = 1; i <= N; ++i) {int u; cin >> u; if (u > max) max = u;}
        cout << max << endl;
    }
    return 0;
}
