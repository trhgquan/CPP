//
// CMPRSS - https://codechef.com/problems/CMPRSS
// Code by @trhgquan - https://github.com/trhgquan
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, N; cin >> T;
    while (T--) {
        cin >> N;
        vector<int>a, b;
        for (int i = 1; i <= N; ++i) {int u; cin >> u; a.push_back(u);b.push_back(1);}

        //
        // The idea is using DP (Dynamic Programming),
        // since we need to count every adjacent subsequence.
        // An element is flagged "1" if it is an edge, or, a single item.
        //
        for (int i = 1; i < N; ++i) {
            if (a[i] - a[i - 1] == 1) b[i] = b[i - 1] + 1;
            if (a[i] - a[i - 1] > 1 && b[i] - b[i - 1] < 0) b[i - 1] = b[i];
            if (i == N - 1 && b[i] != 1) b[i] = 1;
        }

        //
        // Print result
        //
        cout << a[0];
        int c = 1;
        for (int i = 1; i < N; ++i){
            if (b[i] != 1) ++c;
            if (b[i] == 1) {
                if (c >= 2) {
                    cout << "...";
                    c = 1;
                } else cout << ",";
                cout << a[i];
            }
        }
        cout << endl;
    }
    return 0;
}
