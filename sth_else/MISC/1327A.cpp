/**
 * 1327A - https://codeforces.com/problemset/problem/1327/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        long long n, k; cin >> n >> k;
        if (n % 2 == 0 && k % 2 == 0 && n >= k * k) cout << "YES" << endl;
        else if (n % 2 != 0 && k % 2 != 0 && n >= k * k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
