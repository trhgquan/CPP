/**
 * UWCOI20B - https://codechef.com/problems/UWCOI20B
 * UWCOI2020 - online replay on Codechef
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        long N; cin >> N;
        long even = 0; long odds = 0;
        for (int i = 1; i <= N; ++i) {
            long u; cin >> u;
            if (u % 2 == 0) ++even;
            else ++odds;
        }
        long result = even * odds;
        cout << result << endl;
    }
    return 0;
}
