/**
 * P178PROA - https://www.spoj.com/PTIT/problems/P178PROA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(0);
    while (true) {
        long N; cin >> N;
        if (N == 0) break;
        if (N < 1000000) cout << N;
        else if (N >= 1000000 && N <= 5000000) cout << N - (N * 0.1);
        else cout << N - (N * 0.2);
        cout << endl;
    }
    return 0;
}
