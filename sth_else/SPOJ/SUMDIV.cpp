/**
 * SUMDIV - https://www.spoj.com/PTIT/problems/SUMDIV
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ull T; cin >> T;
    while (T--) {
        ull N; cin >> N;
        ull res = 0;
        for (ull i = 1; i < sqrt(N); ++i) {
            if (N % i == 0) {
                ull j = N / i;
                if (i == j) res += i;
                else res = res + i + j;
            }
        }
        ull x = sqrt(N); if (x * x == N) res += x;
        cout << res << endl;
    }

    return 0;
}
