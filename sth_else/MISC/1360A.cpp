/**
 * 1360A - https://codeforces.com/problemset/problem/1360/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        int res = min(max(2 * b, a), max(2 * a, b));
        cout << res * res << endl;
    }

    return 0;
}
