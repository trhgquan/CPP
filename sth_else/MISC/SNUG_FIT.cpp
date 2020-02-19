/**
 * SNUG_FIT - https://codechef.com/problems/SNUG_FIT
 * Codechef February Challenge 2020 - Division 2
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
        int N; cin >> N;
        vector<long>a, b;
        for (int i = 1; i <= N; ++i) {long u; cin >> u; a.push_back(u);}
        for (int i = 1; i <= N; ++i) {long u; cin >> u; b.push_back(u);}

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long S = 0;
        for (int i = 0; i < N; ++i)
            S += min(a[i], b[i]);
        cout << S << endl;
    }
    return 0;
}
