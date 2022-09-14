/**
 * CRDS - https://www.spoj.com/problems/CRDS
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int>a;
    a.push_back(2);
    for (int i = 1; i <= 1000001; ++i)
        a.push_back( (a[i - 1] + (((2 * (i + 1)) + i) % 1000007)) % 1000007);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << a[n - 1] << endl;
    }
    return 0;
}
