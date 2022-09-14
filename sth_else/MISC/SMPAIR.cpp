/**
 * SMPAIR - https://codechef.com/problems/SMPAIR
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T, n; cin >> T;
    while (T--) {
        cin >> n;
        vector<int>a;
        for (int i = 0; i < n; ++i) {int u; cin >> u; a.push_back(u);}
        sort(a.begin(), a.end());
        cout << a[0] + a[1] << endl;
    }
    return 0;
}
