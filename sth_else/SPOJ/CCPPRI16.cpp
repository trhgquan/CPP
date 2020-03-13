/**
 * CCPPRI16 - https://www.spoj.com/PTIT/problems/CCPPRI16
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // Build a sieve
    vector<lli>PRIME(1000001, 1);
    PRIME[0] = 0;
    PRIME[1] = 0;
    for (lli i = 2; i <= 1000000; ++i)
        for (lli j = 2; j * i <= 1000000; ++j) { if (PRIME[i * j]) PRIME[i * j] = 0;}

    int T; cin >> T;
    while (T--) {
        lli N; cin >> N;
        lli count = 0;
        for (lli i = 2; i * i <= N; ++i){
            if (PRIME[i])
                ++count;
        }
        cout << count << endl;
    }
    return 0;
}
