/**
 * ALGOPRO7 - https://www.spoj.com/PTIT/problems/ALGOPRO7
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int>a; for (int i = 1; i <= n; ++i) {int u; cin >> u; a.push_back(u);}
    sort(a.begin(), a.end());

    cout << a[k] << endl;
    return 0;
}
