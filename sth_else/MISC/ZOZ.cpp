/**
 * ZOZ - https://codechef.com/problems/ZOZ
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, k, s = 0, c = 0; cin >> n >> k;
        vector<int>a;
        for(int i = 1; i <= n; ++i) {int u; cin >> u; a.push_back(u); s += u;}
        for (int i = 0; i < n; ++i)
            if (a[i] + k > s - a[i]) c++;
        cout << c << endl;
    }
    return 0;
}
