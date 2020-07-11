/**
 * 1371A - https://codeforces.com/contest/1371/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        long long n; cin >> n;
        if (n % 2 == 0) cout << n / 2;
        else cout << (n + 1) / 2;
        cout << endl;
    }
    return 0;
}
