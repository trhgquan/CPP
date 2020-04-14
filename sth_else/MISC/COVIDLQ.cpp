/**
 * COVIDLQ - https://www.codechef.com/APRIL20B/problems/COVIDLQ
 * Codechef April Long Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int>A;
        for (int i = 1; i <= N; ++i) {
            int u; cin >> u;
            if (u == 1) A.push_back(i);
        }

        bool can = true;
        for (unsigned i = 0; i < A.size() - 1; ++i) {
            if (abs(A[i + 1] - A[i]) < 6) {can = false; break;}
        }

        if (can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
