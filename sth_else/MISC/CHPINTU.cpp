/**
 * CHPINTU - https://www.codechef.com/MARCH20B/problems/CHPINTU
 * Codechef March Long Challenge 2020 - Division 2
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // solution goes here
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        map<int, int>fruits;
        vector<int>num;
        for (int i = 0; i < N; ++i) {
            int u; cin >> u; num.push_back(u);
            fruits.insert(pair<int, int>(u, 0));
        }
        for (int i = 0; i < N; ++i) {
            int u; cin >> u;
            map<int, int>::iterator it = fruits.find(num[i]);
            it->second += u;
        }

        int min = fruits.begin()->second;
        for (auto it = next(fruits.begin()); it != fruits.end(); ++it)
            if (it->second < min) min = it->second;
        cout << min << endl;
    }
    return 0;
}
