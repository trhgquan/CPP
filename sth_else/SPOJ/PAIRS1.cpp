/**
 * [Tutorial] PAIRS1 - Count the pairs
 * https://www.spoj.com/problems/PAIRS1/
 * Code by @trhquan - https://github.com/trhgquan
 * Solution: sorting + binary search
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i: a)
        if (binary_search(a.begin() , a.end(), i + k)) ans++;
    cout << ans;
    return 0;
}
