/**
 * P164SUMA - https://www.spoj.com/PTIT/problems/P164SUMA
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    map<string, int>score;
    for (int i = 1; i <= N; ++i) {
        string s; cin >> s; ++score[s];
    }

    if (score.size() == 1) cout << score.begin()->first;
    else {
        auto team1 = score.begin();
        auto team2 = next(score.begin());

        cout << ((team1->second > team2->second) ? team1->first : team2->first);
    }
    return 0;
}
