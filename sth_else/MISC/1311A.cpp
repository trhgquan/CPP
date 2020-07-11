/**
 * 1311A - https://codeforces.com/problemset/problem/1311A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        ll a, b; cin >> a >> b;
        if (a == b) cout << 0;
        else if (a < b) {
            if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0))
                cout << 2;
            else cout << 1;
        }
        else {
            if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0))
                cout << 1;
            else cout << 2;
        }
        cout << endl;
    }

    return 0;
}
