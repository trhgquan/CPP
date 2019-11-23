/**
 * HIT - Codechef October Lunchtime 2019
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        vector<int> a, s;
        bool e = false;
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {int u; cin >> u; a.push_back(u);}
        sort(a.begin(), a.end());
        for (int i = n / 4; i < n; i += n / 4){
            if (a[i] == a[i - 1]) {
                e = true;
                break;
            } else s.push_back(a[i]);
        }
        if (e) cout << -1 << endl;
        else {
            for (int i: s) cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}
