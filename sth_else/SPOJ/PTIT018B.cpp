/**
 * PTIT018B - https://www.spoj.com/PTIT/problems/PTIT018B
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int>A, B;
        for (int i = 1; i <= N; ++i) {int u; cin >> u; A.push_back(u);}
        for (int i = 1; i <= N; ++i) {int u; cin >> u; B.push_back(u);}

        sort(A.begin(), A.end()); sort(B.begin(), B.end());
        bool found = 0;
        for (int i = 0; i < N; ++i) {
            if (B[i] < A[i]) {found = 1; break;}
        }
        if (found) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
