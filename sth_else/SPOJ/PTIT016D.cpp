/**
 * PTIT016D - https://www.spoj.com/PTIT/problems/PTIT016D
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    vector<int>A; for (int i = 1; i <= N; ++i) {int u; cin >> u; A.push_back(u);}
    sort(A.begin() + 1, A.end(), greater<int>());
    ll res = 0; long i = 0;
    for (i = 0; i <= K; ++i) res = res + A[i];
    for (i = K + 1; i < N; ++i) res = res - A[i];
    cout << res;
    return 0;
}
