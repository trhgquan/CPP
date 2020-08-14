/**
 * P174PROE - https://www.spoj.com/PTIT/problems/P174PROE
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int>series; bool can = true; int N; cin >> N;

    for (int i = 1; i <= N; ++i) {
        int u; cin >> u;
        if (!binary_search(series.begin(), series.end(), u)) {
            if (series.size() == 3) {can = false; break;}
            series.push_back(u); sort(series.begin(), series.end());
        }
    }

    if (series.size() == 3)
        if (series[2] - series[1] != series[1] - series[0]) can = false;

    if (can) cout << "YES";
    else cout << "NO";
    return 0;
}
