/**
 * P174SUMJ - https://www.spoj.com/PTIT/problems/P174SUMJ
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<vector<int>>C(N);
    for (int k = 1; k <= N; ++k) {
        int u; cin >> u;
        for (int i = 0; i < N; ++i){
            if (!binary_search(C[i].begin(), C[i].end(), u)){
                C[i].push_back(u);
                sort(C[i].begin(), C[i].end());
                break;
            }
        }
    }
    vector<int>all;
    for (int i = 0; i < N; ++i) {
        if (C[i].size() > 0) {
            for (unsigned j = 0; j < C[i].size(); ++j)
                all.push_back(C[i][j]);
        } else break;
    }

    int count = 0;
    for (int i = 1; i < N; ++i)
        if (all[i] > all[i - 1]) ++count;
    cout << count << endl;
    return 0;
}
