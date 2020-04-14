/**
 * STRNO - https://www.codechef.com/APRIL20B/problems/STRNO
 * Codechef April Long Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int X, K; cin >> X >> K;
        int can = 0; int divisors = 0; int N = X;

        for (int i = 2; i <= sqrt(N); ++i) {
            while (X % i == 0) {
                X /= i;
                ++divisors;
            }
        }
        if (X > 2) ++divisors;

        if (divisors >= K) can = 1;
        cout << can << endl;
    }

    return 0;
}
