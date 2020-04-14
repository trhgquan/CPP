/**
 * CARSELL - https://www.codechef.com/APRIL20B/problems/CARSELL
 * Codechef April Long Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define MODULO 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<long>P;
        for (int i = 1; i <= N; ++i) {
            long u; cin >> u; P.push_back(u);
        }

        sort(P.begin(), P.end(), greater<long>());
        long sum = P[0] % MODULO;
        for (int i = 1; i < N; ++i) {
            if (P[i] - i >= 0) {
                long substraction = (P[i] % MODULO) - (i % MODULO);
                sum = (sum % MODULO + substraction % MODULO) % MODULO;
            }

        }

        cout << sum << endl;
    }

    return 0;
}
