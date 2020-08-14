/**
 * P161SUMA - https://www.spoj.com/PTIT/problems/P161SUMA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    ll a, b; cin >> a >> b;
    ll res = 0;
    while (b > 0) {
        res += a / b;
        ll c = a % b; a = b; b = c;
    }

    cout << res;

    return 0;
}
