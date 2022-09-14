/**
 * JOHNY - https://codechef.com/problems/JOHNY
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a;
        for (int i = 1; i <= n; ++i) {int u; cin >> u; a.push_back(u);}
        int k, p; cin >> k; p = a[k - 1];
        sort(a.begin(), a.end());

        // Because this is a sort-ed array,
        // we can implement a binary-search
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] > p) r = m - 1;
            else if (a[m] < p) l = m + 1;
            else {
                cout << m + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
