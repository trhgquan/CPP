/**
 * P161PROA - https://www.spoj.com/PTIT/problems/P161PROA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define lli long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<lli>PRIME(1000001, 1);
    PRIME[0] = 0; PRIME[1] = 0;
    for (lli i = 2; i <= 1000000; ++i)
        for (lli j = 2; j * i <= 1000000; ++j)
            if (PRIME[i * j]) PRIME[i * j] = 0;
    lli N; cin >> N;
    while (N--) {
        lli X; cin >> X;
        lli x = sqrt(X);
        if (PRIME[x] && x * x == X) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
