/**
 * LOVEGURU - https://www.spoj.com/problems/LOVEGURU
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int N, K; cin >> N >> K;
    while (N--) {
        string s1, s2; cin >> s1 >> s2;

        set<string>common;

        for (int i = 0; i < (int)s1.size() - K + 1; ++i) {
            string z; // (Can try s1.substr(i, K))
            for (int j = 0; j < K; ++j) z += s1[i + j];
            common.insert(z);
        }

        bool can = false;

        for (int i = 0; i < (int)s2.size() - K + 1; ++i) {
            string z; // (Can try s2.substr(i, k))
            for (int j = 0; j < K; ++j) z += s2[i + j];
            if (common.find(z) != common.end()) {can = true; break;}
        }

        if (can) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
