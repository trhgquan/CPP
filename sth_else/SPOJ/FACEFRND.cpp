/**
 * FACEFRND - https://www.spoj.com/problems/FACEFRND
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Solution goes here
    int N; cin >> N;
    set<string>bro_friends, bob_friends;
    while (N--) {
        string s; cin >> s; bob_friends.insert(s);
        int M; cin >> M;
        for (int i = 1; i <= M; ++i) {
            cin >> s; bro_friends.insert(s);
        }
    }

    int res = 0;

    for (auto it = bro_friends.begin(); it != bro_friends.end(); ++it)
        if (bob_friends.find(*it) == bob_friends.end()) {
            // cout << *it << endl;
            ++res;
        }

    cout << res;

    return 0;
}
