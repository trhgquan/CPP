/**
 * 1388A - https://codeforces.com/contest/1388/problem/A
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        if (N <= 30) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            if (N == 44)
                cout << "5 10 14 15" << endl;
            else if (N == 36)
                cout << "6 10 15 5" << endl;
            else if (N == 40)
                cout << "6 10 15 9" << endl;
            else cout << "6 10 14 " << N - 30 << endl;
        }
    }

    return 0;
}
