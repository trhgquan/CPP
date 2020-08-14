/**
 * P185SUME - https://www.spoj.com/PTIT/problems/P185SUME
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vector<int>num; bool can = true;
    for (int i = 1; i <= N; ++i) {
        int u; cin >> u;
        if (!binary_search(num.begin(), num.end(), u)) num.push_back(u);
        sort(num.begin(), num.end());
    }
    if (num.size() > 3) can = false;
    if (num.size() == 3)
        if (abs(num[0] - num[1]) != abs(num[1] - num[2])) can = false;
    if (can) cout << "YES";
    else cout << "NO";
    return 0;
}
