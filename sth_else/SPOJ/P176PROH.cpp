/**
 * P176PROH - https://www.spoj.com/PTIT/problems/P176PROH
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        vector<ll>a; for (int i = 1; i <= 3; ++i) {ll u; cin >> u; a.push_back(u);}
        sort(a.begin(), a.end());

        cout << a[2] - a[0] << endl;
    }
    return 0;
}
