/**
 * MDL - https://codechef.com/problems/MDL
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, N; cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a, b;
        for (int i = 1; i <= N; ++i) {int u; cin >> u; a.push_back(u); b.push_back(u);}
        sort(a.begin(), a.end());
        int f = 0, l = 0;
        for (int i = 0; i <= N; ++i)
            if (b[i] == a[0]) {f = a[0]; l = a[a.size() - 1]; break;}
            else if (b[i] == a[a.size() - 1]) {f = a[a.size() - 1]; l = a[0]; break;}
        cout << f << ' ' << l << endl;
    }
    return 0;
}
