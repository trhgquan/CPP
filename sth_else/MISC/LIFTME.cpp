/**
 * LIFTME - https://www.codechef.com/COOK117B/problems/LIFTME
 * Codechef April Cookoff 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    long T; cin >> T;
    while (T--) {
        long N, Q; cin >> N >> Q;
        long start = 0;
        long res = 0;
        for (long i = 1; i <= Q; ++i) {
            long f, d; cin >> f >> d;
            res += abs(f - start) + abs(d - f);
            start = d;
        }

        cout << res << endl;
    }

    return 0;
}
